project(counting_inversions_lib)

set(HEADER_FILES
        ith_smallest.h
        )

set(SOURCE_FILES
        ith_smallest.cpp
        )

add_library(ith_smallest_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries( ith_smallest_lib quick_sort_lib)
add_custom_command(TARGET ith_smallest_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygith_smallest_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
