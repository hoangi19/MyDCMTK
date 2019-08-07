#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <dirent.h>
#include <iostream>
#include <queue>
#include <string>

int BFS(int masks[], cv::Mat curImage, int x, int y, int n){
    
    std::queue<int> q;
    
    int rows = curImage.rows;
    int cols = curImage.cols;
    if (masks[x*rows + y] != 0) return 0;
    q.push(x*rows + y);
    int *visited = new int[rows*cols];
    memset(visited, 0, sizeof(visited));

    masks[x*rows + y] = n;

    while (!q.empty())
    {
        int u = q.front();
        
        q.pop();
        if (visited[u]) continue;
        masks[u] = n;
        visited[u] = 1;
        
        if (u%rows + 1 < cols)
            if ((int)curImage.at<uchar>(u/rows, u%rows + 1) != 0 && visited[u+1] == 0) q.push(u+1);
        if (u%rows > 0)
            if ((int)curImage.at<uchar>(u/rows, u%rows - 1) != 0 && visited[u-1] == 0) q.push(u-1);
        if (u+rows < rows*cols)
            if ((int)curImage.at<uchar>(u/rows + 1, u%rows) != 0 && visited[u+rows] == 0) q.push(u+rows);
        if (u/rows > 0)
            if ((int)curImage.at<uchar>(u/rows - 1, u%rows) != 0 && visited[u-rows] == 0) q.push(u-rows);
    }
    delete(visited);

    return 1;
}

int checkMask(cv::Mat preImage, cv::Mat &curImage, cv::Mat befImage){
    
    int rows = curImage.rows;
    int cols = curImage.cols;
    int masks[rows*cols] = {0};
    int cMask = 1;
    
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++){
            if ((int)curImage.at<uchar>(r, c) != 0 && ((int)preImage.at<uchar>(r, c) != 0 || (int)befImage.at<uchar>(r, c) != 0)){
                BFS(masks, curImage, r, c, cMask);
                ++cMask;
            }
        }
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if ((int)curImage.at<uchar>(r, c) != 0 && masks[r*rows + c] == 0)
                curImage.at<uchar>(r, c) = 0;
    return 1;
}

int loadName(std::vector<std::string> &listName, std::string path){
    DIR *dr;
    dr = opendir(path.c_str());
    struct dirent *de;
    while ((de = readdir(dr)) != NULL)
    {
        std::string deName = de->d_name;
        if (deName == "." || deName == "..") continue;
        listName.push_back(deName);
    }
    delete(de);
    closedir(dr);
    return 0;
}

int loadMasks(std::string inpath, std::string outpath){
    DIR *dip;
    if ( (dip = opendir(inpath.c_str())) == NULL) return printf("Folder %s not found!", inpath), 1;
    struct dirent *de;
    while ((de = readdir(dip)) != NULL)
    {
        std::string dename = de->d_name;
       
        if (dename == "." || dename == "..") continue;
        std::vector<std::string> listName;
        std::string path = inpath + "/" + de->d_name + "/";

        loadName(listName, path);
        // create folder if not exist
        std::string outP = outpath + "/" + de->d_name + "/";
        DIR *dircheck;
        dircheck = opendir(outP.c_str());
        if (dircheck == NULL){
            std::string cmd = "mkdir \"" + outP + "\"";
            system(cmd.c_str());
        }
        
        cv::Mat firstImage = cv::imread(path + listName[0], 0);
        bool flag = cv::imwrite(outP + listName[0], firstImage);
        if (flag) std::cout << "Done! :";
            else std::cout << "Error! :";
        std::cout << outP + listName[0] << "\n";

        for (int i = 1; i < listName.size()-1; i++){
            cv::Mat preImage = cv::imread(path + listName[i-1], 0);
            cv::Mat curImage = cv::imread(path + listName[i], 0);
            cv::Mat befImage = cv::imread(path + listName[i+1], 0);

            checkMask(preImage, curImage, befImage);

            bool flag = cv::imwrite(outP + listName[i], curImage);
            if (flag) std::cout << "Done! :";
                else std::cout << "Error! :";
            std::cout << outP + listName[i] << "\n";
        }

        cv::Mat lastImage = cv::imread(path + listName[listName.size()-1], 0);
        flag = cv::imwrite(outP + listName[listName.size()-1], lastImage);
        if (flag) std::cout << "Done! :";
            else std::cout << "Error! :";
        std::cout << outP + listName[listName.size()-1] << "\n";
    }
    delete(de);
    closedir(dip);

    
    return 0;
}

int main(int argc, char const *argv[])
{
    std::string inpath, outpath;
    inpath = argv[1];
    outpath = argv[2];

    DIR *dircheck;
    dircheck = opendir(outpath.c_str());
    if (dircheck == NULL){
        std::string cmd = "mkdir \"" + outpath + "\"";
        system(cmd.c_str());
    }

    // std::cout << "input path : ";
    // std::cin >> inpath;
    // std::cout << "output path : ";
    // std::cin >> outpath;
    // std::cin >> path;
    if (loadMasks(inpath, outpath)) return 1;
    return 0;
}
