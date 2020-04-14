# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} common number_multiply second_largest_number
        quick_sort ith_smallest min_cut unimodal_search backspace_process contiguous_array)

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run NumberTest.cpp count_inversions_test.cpp second_largest_test.cpp quick_sort_test.cpp
        ith_smallest_test.cpp ith_smallest_test.cpp karget_min_cut_test.cpp search_in_unimodal_test.cpp
        backspace_process_test.cpp min_stack_test.cpp tree_diameter_test.cpp contiguous_array_test.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main common_lib number_multiply_lib count_inversions_lib
        second_largest_lib quick_sort_lib ith_smallest_lib min_cut_lib unimodal_search_lib backspace_process_lib
        contiguous_array_lib)
