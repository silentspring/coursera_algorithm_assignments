project(counting_inversions_lib)

set(HEADER_FILES
        second_largest.h
        )

set(SOURCE_FILES
        second_largest.cpp
        )

add_library(second_largest_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})