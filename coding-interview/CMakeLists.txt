cmake_minimum_required(VERSION 3.10)

# set the project name
project(CodingInterview VERSION 1.0)

# add the executable
add_executable(sort_words sort_words.cpp)
add_executable(inspect_bits inspect_bits.cpp)
add_executable(user_info user_info.cpp)
add_executable(quadratic_equation quadratic_equation.cpp)
add_executable(inheritance inheritance.cpp)
add_executable(binary_search_tree binary_search_tree.c)
add_executable(merge_names merge_names.cpp)
add_executable(watched_videos watched_videos.c)
add_executable(sorted_search sorted_search.cpp)
add_executable(sorted_search_1 sorted_search_1.cpp)
add_executable(song song.cpp)
add_executable(two_sum_1 two_sum_1.cpp)



# specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set debug flag
set(CMAKE_BUILD_TYPE Debug)