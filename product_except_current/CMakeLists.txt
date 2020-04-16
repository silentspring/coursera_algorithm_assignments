project(product_except_current_lib)

set(HEADER_FILES
        product_except_current.h
        )

set(SOURCE_FILES
        product_except_current.cpp
        )

add_library(product_except_current_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET product_except_current_lib
        POST_BUILD
        COMMAND cp cygproduct_except_current_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
