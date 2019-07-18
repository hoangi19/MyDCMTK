project(GetContour)

find_package(DCMTK REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(getContour getContour.cpp)

include_directories(${DCMTK_INCLUDE_DIRS})

target_link_libraries(getContour ${DCMTK_LIBRARIES})
