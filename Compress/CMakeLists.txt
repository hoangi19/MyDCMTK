cmake_minimum_required(VERSION 2.8)

project( CompressDicom2JPEG )

#set(CMAKE_CXX_STANDARD_REQUIRED 11)

if ( CMAKE_COMPILER_IS_GNUCXX )
	set(DMCTK_DIR "G:\\Code\\DCMTK")
elseif( CMAKE_CL_64 )
	set(DCMTK_DIR "C:\\Program Files (x86)\\DCMTK")
endif()

find_package(DCMTK)

include_directories(${DCMTK_INCLUDE_DIRS})

add_executable(Compress Compress.cpp)
target_link_libraries(Compress ${DCMTK_LIBRARIES})
