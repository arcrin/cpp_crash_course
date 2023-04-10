//
// Created by andy- on 2023-04-09.
// set array values to the even integers from 2 to 10
//
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
    // constant can be used to specify array size
    constexpr size_t arraySize{5}; // must initialize in declaration

    std::array<int, arraySize> values{}; // array values has 5 elements

}
