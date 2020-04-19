project(valid_parenthesis_string_lib)

set(HEADER_FILES
        valid_parenthesis_string.h
        )

set(SOURCE_FILES
        valid_parenthesis_string.cpp
        )

add_library(valid_parenthesis_string_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET valid_parenthesis_string_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygvalid_parenthesis_string_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
