project(counting_inversions_lib)

set(HEADER_FILES
        ith_smallest.h
        )

set(SOURCE_FILES
        ith_smallest.cpp
        )

add_library(ith_smallest_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})