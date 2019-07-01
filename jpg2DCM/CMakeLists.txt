project(jpg2dcm)

set(DICOM_DIR "C:\\Program Files (x86)\\DCMTK")

#SET(OpenCV_DIR "G:\\Code\\opencv-3.4.5\\opencv-3.4.5\\build\\install")

find_package(DCMTK)

#find_package(OpenCV)

include_directories(${DCMTK_DIR}/include)
#include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(jpg2dcm jpg2dcm.cpp)

#target_link_libraries(jpg2dcm ${OpenCV_LIBS})
target_link_libraries(jpg2dcm ${DCMTK_LIBRARIES})