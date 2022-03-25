# CMakeList.txt : CMake project for BasicProgram, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("BasicProgram")

# Add source to this project's executable.
add_executable (BasicProgram "BasicProgram.cpp" "BasicProgram.h" "ezOptionParser.hpp")

# TODO: Add tests and install targets if needed.

enable_testing()

add_executable(my_test tests.cpp)
add_test(Test1 my_test)
