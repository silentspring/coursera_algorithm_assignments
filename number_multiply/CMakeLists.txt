project(number_multiply_lib)

set(HEADER_FILES
        Number.h
        Operator.h
        )

set(SOURCE_FILES
        Number.cpp
        Operator.cpp
        )

add_library(number_multiply_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET number_multiply_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygnumber_multiply_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
