cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(libevent-helloworld VERSION 0.1.0)

set(
    SOURCE_FILES
    libevent-helloworld.cpp

    # libevent-helloworld-1.cpp
)

set(
    TARGET_FILE
    libevent-helloworld
)

set(CMAKE_INSTALL_RPATH "/usr/local/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# add_library(lins355_static STATIC ${SOURCE_FILES})
include(CTest)
enable_testing()

# add the executable
add_executable(
    ${TARGET_FILE}

    ${SOURCE_FILES}
)

# include dir
# include_directories(
# libserial
# libserial/src
# )

# Directories of 3rd lib
# link_directories(
# libserial/build/lib
# )
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set debug flag
set(CMAKE_BUILD_TYPE Debug)

# add_subdirectory(
# libserial
# unit_test
# )

# Link neccessary libraries, include 3rd libraries
target_link_libraries(
    ${TARGET_FILE}

    pthread
    event
)