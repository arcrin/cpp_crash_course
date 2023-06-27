//
// Created by andy- on 2023-04-10.
// compute the sum of an array's elements
//
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
    std::array items{10, 20, 30, 40}; // type inferred as std::array<int, 4>
    int total{0};

    // sum the contents of items
    for (const int &item: items) {
        total += item;
    }
    std::cout << fmt::format("Total of array elements: {}\n", total);
}
