project (DeCompressJPEG)

set(DICOM_DIR "C:\\Program Files (x86)\\DCMTK")

find_package (DCMTK)

include_directories(${DCMTK_INCLUDE_DIRS})

add_executable(decode DeCompress.cpp)

target_link_libraries(decode ${DCMTK_LIBRARIES})