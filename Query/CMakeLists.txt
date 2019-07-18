project(StoreSCU)

set(DCMTK_DIR "G:\\Code\\DCMTKPACKAGE\\DCMTK")



add_executable(StoreSCU storescu.cpp)

find_package(DCMTK)
find_package(TIFF)

include_directories(${DCMTK_INCLUDE_DIR})

target_link_libraries(StoreSCU ${DCMTK_LIBRARIES})