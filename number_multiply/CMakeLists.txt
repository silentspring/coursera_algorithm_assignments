project(number_multiply_lib)

set(HEADER_FILES
        Number.h
        Operator.h
        )

set(SOURCE_FILES
        Number.cpp
        Operator.cpp
        )

add_library(number_multiply_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})