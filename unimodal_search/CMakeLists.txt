project(unimodal_search_lib)

set(HEADER_FILES
        unimodal_search.h
        )

set(SOURCE_FILES
        unimodal_search.cpp
        )

add_library(unimodal_search_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET unimodal_search_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygunimodal_search_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
