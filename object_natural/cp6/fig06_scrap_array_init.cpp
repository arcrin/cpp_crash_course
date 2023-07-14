//
// Created by wbai on 6/23/2023.
//

#include <array>
#include <fmt/format.h>
#include <iostream>


int main() {
    std::array<int, 5> values{};

    std::cout << fmt::format("{:>7}{:>10}\n", "Element", "Value");

    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << fmt::format("{:>7}{:>10}\n", i, values[i]);
    }
//    std::cout << values[5]; // [] operator does not bound check
}