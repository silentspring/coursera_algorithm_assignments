project(quick_sort_lib)

set(HEADER_FILES
        quick_sort.h
        )

set(SOURCE_FILES
        quick_sort.cpp
        )

add_library(quick_sort_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET quick_sort_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygquick_sort_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
