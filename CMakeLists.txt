cmake_minimum_required(VERSION 3.12)
project(lr6)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRCS
    "include/*.h"
    "src/lib/*.cpp"
)

file(GLOB_RECURSE TEST_SRCS
    "include/*.h"
    "tests/*.cpp"
)

include_directories(AFTER "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(lr6_lib ${SRCS})

add_executable(lr6 src/main.cpp include/matrix_1d_array.h include/matrix.h)
add_executable(lr6_test ${TEST_SRCS})

target_link_libraries(lr6 lr6_lib)
target_link_libraries(lr6_test lr6_lib)