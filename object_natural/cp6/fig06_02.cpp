//
// Created by andy- on 2023-04-09.
// initializing an array in a declaration
//
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
    std::array<int, 5> values{32, 27, 64, 18, 95}; // braced initializer

    // output each array element's value
    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << fmt::format("{}    ", values.at(i));
    }
    std::cout << "\n\n";

    // using class template argument deduction to determine values2's type
    std::array values2{1.1, 2.2, 3.3, 4.4};

    // output each array element's value
    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << fmt::format("{}    ", values2.at(i));
    }

    std::cout << "\n";
}
