project(counting_inversions_lib)

set(HEADER_FILES
        min_cut.h
        )

set(SOURCE_FILES
        min_cut.cpp
        )

add_library(min_cut_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET min_cut_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygmin_cut_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
