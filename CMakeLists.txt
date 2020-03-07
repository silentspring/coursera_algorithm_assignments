cmake_minimum_required(VERSION 3.14)
project(assignments)

set(CMAKE_CXX_STANDARD 14)

include_directories(number_multiply common)
add_subdirectory(Google_tests )
add_subdirectory(common)
add_subdirectory(number_multiply)

