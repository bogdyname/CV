# CMakeList.txt : CMake project for MSL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (MSL "MSL.cpp" "MSL.h" "geometry/include/geometry.hpp" "geometry/src/geometry.cpp")

# TODO: Add tests and install targets if needed.
