project(common_lib)

set(HEADER_FILES
        common.h
        )

set(SOURCE_FILES
        common.cpp
        ../ith_smallest/ith_smallest.h ../ith_smallest/ith_smallest.h ../unimodal_search/unimodal_search.cpp ../unimodal_search/unimodal_search.h ../backspace_process/backspace_process.cpp ../backspace_process/backspace_process.h)

add_library(common_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET common_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygcommon_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
