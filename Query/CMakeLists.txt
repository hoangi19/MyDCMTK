project(FindSCU)

set(DCMTK_DIR "G:\\Code\\DCMTKPACKAGE\\DCMTK")



add_executable(FindSCU findscu.cpp)

find_package(DCMTK)
find_package(TIFF)

include_directories(${DCMTK_INCLUDE_DIR})

target_link_libraries(FindSCU ${DCMTK_LIBRARIES})