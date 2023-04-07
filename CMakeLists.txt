cmake_minimum_required(VERSION 3.24)
project(cpp_crash_course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

add_library(fmt STATIC IMPORTED object_natural/cp4/fig04_01.cpp)
set_target_properties(fmt PROPERTIES
        IMPORTED_LOCATION "C:/Learning/cpp_crash_course/libraries/fmt/lib/libfmt.a"
        INTERFACE_INCLUDE_DIRECTORIES "C:/Learning/cpp_crash_course/libraries/fmt/include")

add_library(BigNumber STATIC IMPORTED object_natural/cp4/fig04_01.cpp object_natural/cp4/fig04_01.cpp object_natural/cp4/fig04_01.cpp object_natural/cp5/fig05_03.cpp object_natural/cp5/fig05_03.cpp object_natural/cp5/fig05_05.cpp object_natural/cp5/fig05_09.cpp)
set_target_properties(BigNumber PROPERTIES
        IMPORTED_LOCATION "C:/Learning/cpp_crash_course/libraries/BigNumber/lib/libBigNumber.a"
        INTERFACE_INCLUDE_DIRECTORIES "C:/Learning/cpp_crash_course/libraries/BigNumber/include"
)

add_executable(cpp_crash_course
                object_natural/cp5/fig05_18.cpp)

target_link_libraries(cpp_crash_course
        fmt
        BigNumber
)
