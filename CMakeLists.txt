cmake_minimum_required(VERSION 3.14)
project(assignments)

set(CMAKE_CXX_STANDARD 14)

include_directories(common number_multiply count_inversions second_largest_number quick_sort ith_smallest min_cut
        unimodal_search backspace_process min_stack tree_diameter contiguous_array)
add_subdirectory(Google_tests)
add_subdirectory(common)
add_subdirectory(number_multiply)
add_subdirectory(count_inversions)
add_subdirectory(second_largest_number)
add_subdirectory(quick_sort)
add_subdirectory(ith_smallest)
add_subdirectory(min_cut)
add_subdirectory(unimodal_search)
add_subdirectory(backspace_process)
add_subdirectory(min_stack)
add_subdirectory(tree_diameter)
add_subdirectory(contiguous_array)

