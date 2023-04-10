cmake_minimum_required(VERSION 3.24)
project(cpp_crash_course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

add_library(fmt STATIC IMPORTED object_natural/cp4/fig04_01.cpp)
set_target_properties(fmt PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libraries/fmt/lib/libfmt.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/libraries/fmt/include")

add_library(BigNumber STATIC IMPORTED object_natural/cp6/fig06_01.cpp object_natural/cp6/fig06_02.cpp object_natural/cp6/fig06_03.cpp object_natural/cp6/fig06_04.cpp)
set_target_properties(BigNumber PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libraries/BigNumber/lib/libBigNumber.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/libraries/BigNumber/include"
)

add_executable(cpp_crash_course
                object_natural/cp6/fig06_03.cpp object_natural/cp6/fig06_04.cpp)

target_link_libraries(cpp_crash_course
        fmt
        BigNumber
)
