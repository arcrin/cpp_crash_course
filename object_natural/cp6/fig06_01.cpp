//
// Created by andy- on 2023-04-09.
// initializing an array's elements to zeros and printing the array
//
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
    std::array<int, 5> values{}; // values is an array of 5 int values

    // initialize elements of array values to 0
//    for (size_t i{0}; i < values.size(); ++i) {
//        values[i] = 0; // set element at location i to 0
//    }

    std::cout << fmt::format("{:>7}{:>10}\n", "Element", "Value");

    // output each array element's value
    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << fmt::format("{:>7}{:>10}\n", i, values[i]);
    }

    std::cout << fmt::format("\n{:>7}{:>10}\n", "Element", "Value");

    // access elements via the at member fucntion
    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << fmt::format("{:>7}{:>10}\n", i, values.at(i));
    }

    // accessing an element outside the array's bounds with at
    values.at(10); //
}
