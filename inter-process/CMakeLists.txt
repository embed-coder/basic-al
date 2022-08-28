cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(inter-process VERSION 0.1.0)

include(CTest)
enable_testing()

# Add a subdirectory to the build
add_subdirectory(server)
add_subdirectory(client)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set debug flag
set(CMAKE_BUILD_TYPE Debug)