project(common_lib)

set(HEADER_FILES
        common.h
        )

set(SOURCE_FILES
        common.cpp
        )

add_library(common_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})