project(min_stack_lib)

set(HEADER_FILES
        min_stack.h
        )

set(SOURCE_FILES
        min_stack.cpp
        )

add_library(min_stack_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET min_stack_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygmin_stack_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
