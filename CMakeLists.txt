cmake_minimum_required(VERSION 3.24)
project(cpp_crash_course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
add_executable(cpp_crash_course
        object_natural/cp5/fig05_02.cpp)
target_link_libraries(cpp_crash_course fmt)