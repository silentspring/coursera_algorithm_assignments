project(common_lib)

set(HEADER_FILES
        common.h
        )

set(SOURCE_FILES
        common.cpp
        ../ith_smallest/ith_smallest.cpp ../ith_smallest/ith_smallest.h)

add_library(common_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})