cmake_minimum_required(VERSION 3.24)
project(cpp_crash_course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
add_executable(cpp_crash_course
        object_natural/cp5/fig05_05.cpp
        object_natural/include/fmt/args.h
        object_natural/include/fmt/chrono.h
        object_natural/include/fmt/compile.h
        object_natural/include/fmt/core.h
        object_natural/include/fmt/format.h
        object_natural/include/fmt/format-inl.h
        object_natural/include/fmt/os.h
        object_natural/include/fmt/ostream.h
        object_natural/include/fmt/printf.h
        object_natural/include/fmt/ranges.h
        object_natural/include/fmt/std.h
        object_natural/include/fmt/xchar.h
        object_natural/src/fmt.cc
        object_natural/src/format.cc
        object_natural/src/os.cc
        )


