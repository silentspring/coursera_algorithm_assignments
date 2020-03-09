project(counting_inversions_lib)

set(HEADER_FILES
        count_inversions.h
        )

set(SOURCE_FILES
        count_inversions.cpp
        )

add_library(counting_inversions_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})