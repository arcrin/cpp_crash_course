//
// Created by wbai on 6/27/2023.
//
#include <array>
#include <iostream>
#include <fmt/format.h>


int main() {
    auto showValues{
            [](const auto &md_array, const std::string &message) {
                std::cout << fmt::format("{}\n", message);
                for (const auto &row: md_array) {
                    for (const auto &value: row) {
                        std::cout << fmt::format("{} ", value);
                    }
                    std::cout << '\n';
                }
            }
    };

    constexpr int columns{3};
    constexpr int rows{2};
    // initialize with a fully braced initializer list
    constexpr std::array<std::array<int, columns>, rows> const_array{
        // evaluated at compile time, values can not be reassigned
            {
                    {3, 2, 3},
                    {1, 5, 6}
            }
    };

    std::array<std::array<int, columns>, rows> normal_array{}; // initialize to all zeros

    // print out const_array
    showValues(const_array, "Print out const_array");

    // print out normal_array
    showValues(normal_array, "Print out normal_array");

    // change values normal_array column one to 2
    for (size_t row{0}; row < normal_array.size(); ++row) {
        normal_array.at(row).at(1) = 1;
    }

    showValues(normal_array, "Print out normal_array after modification");

    // sum up all elements in const_array
    int total{0};
    for (const auto &row: const_array) { // if there is no intention of changing the value, use const
        for (const auto &value: row) {
            total += value;
        }
    }

    std::cout << fmt::format("Total sum of const_array: {}", total);
}