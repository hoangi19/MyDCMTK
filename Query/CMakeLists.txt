project(findscu)

set(DCMTK_DIR "G:\\Code\\DCMTKPACKAGE\\DCMTK")

add_executable(findscu findscu.cpp)

find_package(DCMTK)

include_directories(${DCMTK_INCLUDE_DIR})

target_link_libraries(findscu ${DCMTK_LIBRARIES})