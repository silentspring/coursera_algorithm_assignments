project(num_islands_lib)

set(HEADER_FILES
        num_islands.h
        )

set(SOURCE_FILES
        num_islands.cpp
        )

add_library(num_islands_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET num_islands_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygnum_islands_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
