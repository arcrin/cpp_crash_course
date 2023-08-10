cmake_minimum_required(VERSION 3.20)
project(cpp_crash_course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

add_compile_definitions(FMT_HEADER_ONLY)

link_directories("mnt/c/usr/local/include")

add_library(fmt STATIC IMPORTED libraries/fmt/include/fmt/format.h)
set_target_properties(fmt PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libraries/fmt/lib/libfmt.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/libraries/fmt/include")

add_library(BigNumber STATIC IMPORTED
        libraries/BigNumber/include/bignumber.h)
set_target_properties(BigNumber PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libraries/BigNumber/lib/libBigNumber.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/libraries/BigNumber/include"
)

set(PROJECT_FILES
        object_natural/cp12/DivideByZeroException.h
)

add_executable(${PROJECT_NAME}
        ${PROJECT_FILES}
        object_natural/cp13/fig13_01_input_output_with_iterators.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        fmt
        BigNumber
)
