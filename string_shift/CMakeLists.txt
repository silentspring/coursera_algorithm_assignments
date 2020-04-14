project(string_shift_lib)

set(HEADER_FILES
        string_shift.h
        )

set(SOURCE_FILES
        string_shift.cpp
        )

add_library(string_shift_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET string_shift_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygstring_shift_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
