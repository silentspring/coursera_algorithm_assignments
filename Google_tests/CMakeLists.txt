# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} common number_multiply second_largest_number quick_sort)

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run NumberTest.cpp count_inversions_test.cpp second_largest_test.cpp quick_sort_test.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main common_lib number_multiply_lib count_inversions_lib second_largest_lib quick_sort_lib)
