# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = G:\Cmake\bin\cmake.exe

# The command to remove a file.
RM = G:\Cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Hoangi19\Desktop\CompressDicom\Compress

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Hoangi19\Desktop\CompressDicom\Compress\buildMinGW

# Include any dependencies generated for this target.
include CMakeFiles/Compress.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Compress.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Compress.dir/flags.make

CMakeFiles/Compress.dir/Compress.cpp.obj: CMakeFiles/Compress.dir/flags.make
CMakeFiles/Compress.dir/Compress.cpp.obj: CMakeFiles/Compress.dir/includes_CXX.rsp
CMakeFiles/Compress.dir/Compress.cpp.obj: ../Compress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Hoangi19\Desktop\CompressDicom\Compress\buildMinGW\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Compress.dir/Compress.cpp.obj"
	G:\Code\MinGW64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Compress.dir\Compress.cpp.obj -c C:\Users\Hoangi19\Desktop\CompressDicom\Compress\Compress.cpp

CMakeFiles/Compress.dir/Compress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compress.dir/Compress.cpp.i"
	G:\Code\MinGW64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Hoangi19\Desktop\CompressDicom\Compress\Compress.cpp > CMakeFiles\Compress.dir\Compress.cpp.i

CMakeFiles/Compress.dir/Compress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compress.dir/Compress.cpp.s"
	G:\Code\MinGW64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Hoangi19\Desktop\CompressDicom\Compress\Compress.cpp -o CMakeFiles\Compress.dir\Compress.cpp.s

# Object files for target Compress
Compress_OBJECTS = \
"CMakeFiles/Compress.dir/Compress.cpp.obj"

# External object files for target Compress
Compress_EXTERNAL_OBJECTS =

Compress.exe: CMakeFiles/Compress.dir/Compress.cpp.obj
Compress.exe: CMakeFiles/Compress.dir/build.make
Compress.exe: G:/Code/DCMTK/lib/libofstd.a
Compress.exe: G:/Code/DCMTK/lib/liboflog.a
Compress.exe: G:/Code/DCMTK/lib/libdcmdata.a
Compress.exe: G:/Code/DCMTK/lib/libi2d.a
Compress.exe: G:/Code/DCMTK/lib/libdcmimgle.a
Compress.exe: G:/Code/DCMTK/lib/libdcmimage.a
Compress.exe: G:/Code/DCMTK/lib/libdcmjpeg.a
Compress.exe: G:/Code/DCMTK/lib/libijg8.a
Compress.exe: G:/Code/DCMTK/lib/libijg12.a
Compress.exe: G:/Code/DCMTK/lib/libijg16.a
Compress.exe: G:/Code/DCMTK/lib/libdcmjpls.a
Compress.exe: G:/Code/DCMTK/lib/libcharls.a
Compress.exe: G:/Code/DCMTK/lib/libdcmtls.a
Compress.exe: G:/Code/DCMTK/lib/libdcmnet.a
Compress.exe: G:/Code/DCMTK/lib/libdcmsr.a
Compress.exe: G:/Code/DCMTK/lib/libcmr.a
Compress.exe: G:/Code/DCMTK/lib/libdcmdsig.a
Compress.exe: G:/Code/DCMTK/lib/libdcmwlm.a
Compress.exe: G:/Code/DCMTK/lib/libdcmqrdb.a
Compress.exe: G:/Code/DCMTK/lib/libdcmpstat.a
Compress.exe: G:/Code/DCMTK/lib/libdcmrt.a
Compress.exe: G:/Code/DCMTK/lib/libdcmiod.a
Compress.exe: G:/Code/DCMTK/lib/libdcmfg.a
Compress.exe: G:/Code/DCMTK/lib/libdcmseg.a
Compress.exe: G:/Code/DCMTK/lib/libdcmtract.a
Compress.exe: G:/Code/DCMTK/lib/libdcmpmap.a
Compress.exe: G:/Code/DCMTK/lib/libdcmtls.a
Compress.exe: G:/Code/DCMTK/lib/libdcmsr.a
Compress.exe: G:/Code/DCMTK/lib/libdcmimage.a
Compress.exe: G:/Code/dcmtkpackage/tiff/lib/libtiff.dll.a
Compress.exe: G:/Code/dcmtkpackage/libpng/lib/libpng.dll.a
Compress.exe: G:/Code/DCMTK/lib/libdcmdsig.a
Compress.exe: G:/Code/DCMTK/lib/libdcmqrdb.a
Compress.exe: G:/Code/DCMTK/lib/libdcmnet.a
Compress.exe: G:/Code/DCMTK/lib/libdcmimgle.a
Compress.exe: G:/Code/DCMTK/lib/libdcmfg.a
Compress.exe: G:/Code/DCMTK/lib/libdcmiod.a
Compress.exe: G:/Code/DCMTK/lib/libdcmdata.a
Compress.exe: G:/Code/DCMTK/lib/liboflog.a
Compress.exe: G:/Code/DCMTK/lib/libofstd.a
Compress.exe: G:/Code/dcmtkpackage/zlib/lib/libzlib.dll
Compress.exe: CMakeFiles/Compress.dir/linklibs.rsp
Compress.exe: CMakeFiles/Compress.dir/objects1.rsp
Compress.exe: CMakeFiles/Compress.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Hoangi19\Desktop\CompressDicom\Compress\buildMinGW\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Compress.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Compress.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Compress.dir/build: Compress.exe

.PHONY : CMakeFiles/Compress.dir/build

CMakeFiles/Compress.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Compress.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Compress.dir/clean

CMakeFiles/Compress.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Hoangi19\Desktop\CompressDicom\Compress C:\Users\Hoangi19\Desktop\CompressDicom\Compress C:\Users\Hoangi19\Desktop\CompressDicom\Compress\buildMinGW C:\Users\Hoangi19\Desktop\CompressDicom\Compress\buildMinGW C:\Users\Hoangi19\Desktop\CompressDicom\Compress\buildMinGW\CMakeFiles\Compress.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Compress.dir/depend
