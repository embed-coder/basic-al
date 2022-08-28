cmake_minimum_required(VERSION 3.10)

# set the project name
project(QuickSort VERSION 1.0)

# add the executable
add_executable(quicksort quicksort.cpp)
add_executable(mergesort mergesort.cpp)
add_executable(romannumber romannumber.cpp)
add_executable(factorial factorial.cpp)
add_executable(basicFunction basicFunction.cpp)

# specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set debug flag
set(CMAKE_BUILD_TYPE Debug)