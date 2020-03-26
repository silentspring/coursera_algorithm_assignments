project(counting_inversions_lib)

set(HEADER_FILES
        quick_sort.h
        )

set(SOURCE_FILES
        quick_sort.cpp
        )

add_library(quick_sort_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})