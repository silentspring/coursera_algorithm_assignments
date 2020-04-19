project(min_sum_path_lib)

set(HEADER_FILES
        min_sum_path.h
        )

set(SOURCE_FILES
        min_sum_path.cpp
        )

add_library(min_sum_path_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET min_sum_path_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygmin_sum_path_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
