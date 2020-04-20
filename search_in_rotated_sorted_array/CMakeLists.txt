project(search_in_rotated_sorted_array_lib)

set(HEADER_FILES
        search_in_rotated_sorted_array.h
        )

set(SOURCE_FILES
        search_in_rotated_sorted_array.cpp
        )

add_library(search_in_rotated_sorted_array_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET search_in_rotated_sorted_array_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygsearch_in_rotated_sorted_array_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
