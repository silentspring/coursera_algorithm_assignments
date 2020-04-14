project(contiguous_array_lib)

set(HEADER_FILES
        contiguous_array.h
        )

set(SOURCE_FILES
        contiguous_array.cpp)

add_library(contiguous_array_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET contiguous_array_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygcontiguous_array_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
