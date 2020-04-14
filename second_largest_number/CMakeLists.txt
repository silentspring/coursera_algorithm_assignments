project(counting_inversions_lib)

set(HEADER_FILES
        second_largest.h
        )

set(SOURCE_FILES
        second_largest.cpp
        )

add_library(second_largest_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET second_largest_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygsecond_largest_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
