project(backspace_process_lib)

set(HEADER_FILES
        backspace_process.h
        )

set(SOURCE_FILES
        backspace_process.cpp)

add_library(backspace_process_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET backspace_process_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygbackspace_process_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
