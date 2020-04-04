project(counting_inversions_lib)

set(HEADER_FILES
        min_cut.h
        )

set(SOURCE_FILES
        min_cut.cpp
        )

add_library(min_cut_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})