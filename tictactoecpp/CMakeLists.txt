cmake_minimum_required(VERSION 3.10)

# set the project name
project(TicTacToe VERSION 1.0)

# add the executable
add_executable(tictactoe tictactoe.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set debug flag
set(CMAKE_BUILD_TYPE Debug)