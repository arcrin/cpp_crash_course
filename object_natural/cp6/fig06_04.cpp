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

    std::array<size_t, arraySize> values{}; // array values has 5 elements

    for (int i{0}; i < values.size(); ++i) {
        values.at(i) = 2 + 2 * i;
    }

    // output contents of array values in tabular format
    for (const size_t &value: values) {
        std::cout << fmt::format("{} ", value);
    }
    std::cout << "\n";
}
