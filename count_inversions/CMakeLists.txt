project(counting_inversions_lib)

set(HEADER_FILES
        count_inversions.h
        )

set(SOURCE_FILES
        count_inversions.cpp
        )

add_library(count_inversions_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET count_inversions_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygcount_inversions_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
