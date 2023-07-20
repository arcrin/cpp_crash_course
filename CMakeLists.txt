cmake_minimum_required(VERSION 3.24)
project(cpp_crash_course)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

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

message(${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_FILES
        object_natural/cp9/Time.cpp
        object_natural/cp9/Time.h
        object_natural/cp9/CreateAndDestroy.h
        object_natural/cp9/CreateAndDestroy.cpp
        object_natural/cp9/BadTimeClass.h
        object_natural/cp9/BadTimeClass.cpp
        object_natural/cp9/Date.h
        object_natural/cp9/Date.cpp
        object_natural/cp9/Employee.h
        object_natural/cp9/Employee.cpp
        )


add_executable(cpp_crash_course
        ${PROJECT_FILES} object_natural/cp9/fig09_36_serialization.cpp)


target_link_libraries(cpp_crash_course PRIVATE
        fmt
        BigNumber
)
