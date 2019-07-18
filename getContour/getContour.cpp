#include "dcmtk/dcmdata/dcitem.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include <fstream>
#include <iostream>
#include <dirent.h>

int main(int argc, char const *argv[])
{
    //std::filesystem::
    DIR *dir;
    std::string path = "../image/";
    if ((dir = opendir(path.c_str())) == NULL){
        std::cout << "folder not found!";
        return 1;
    }
    struct dirent *ent;
    int id = 0;
    while ((ent = readdir (dir)) != NULL) {
        std::string s = ent->d_name;
        printf ("%s\n", ent->d_name);
        std::string cmd = "dcm2pnm +on2 -S +Wi 1 ../image/" + s + " ../png/res"+ std::to_string(id).c_str() + ".png";
        system(cmd.c_str());
        id++;
    }
    closedir (dir);
    
    DcmFileFormat fileformat;
    if (fileformat.loadFile("../RT.dcm").bad()){
        std::cout << "file not found!";
        return 1;
    }
    signed long i = 0;
    DcmItem *roiitem = NULL;
    DcmItem *contouritem = NULL;
    std::ofstream myfile("../rt.txt");
    while (fileformat.getDataset()->findAndGetSequenceItem(DCM_ROIContourSequence, roiitem, i++).good())
    {
    // roiitem now points to one item in the ROIContourSequence
        signed long j = 0;
        while (roiitem->findAndGetSequenceItem(DCM_ContourSequence, contouritem , j++).good())
        {
            // contouritem now points to some item in the ContourSequence
            // There are different ways to access the contour data.
            // The following approach is simple but not the most efficient one.
            Float64 v = 0.0;
            unsigned long k = 0;
            while (contouritem->findAndGetFloat64(DCM_ContourData, v, k++).good())
            {
                // here's one number from the contour data array,
                // already converted to floating point (i.e., double).
                myfile << v << ", ";
            }   
        }  
    }
    return 0;
}
