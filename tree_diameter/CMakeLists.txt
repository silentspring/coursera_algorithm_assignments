project(tree_diameter_lib)

set(HEADER_FILES
        tree_diameter.h
        )

set(SOURCE_FILES
        tree_diameter.cpp)

add_library(tree_diameter_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_custom_command(TARGET tree_diameter_lib
        # Run after all other rules within the target have been executed
        POST_BUILD
        COMMAND cp cygtree_diameter_lib.dll ../Google_tests/
        COMMENT
        VERBATIM
        )
