//
// Created by wbai on 7/4/2023.
//

#include <array>
#include <iostream>
#include <fmt/format.h>

int main() {
    const auto displayBuiltInArray{
            [](const int *values, const int numberOfElements) {
                for (int i{0}; i < numberOfElements; ++i) {
                    std::cout << fmt::format("{} ", values[i]);
                }
                std::cout << '\n';
            }
    };

    int n[5]{5, 4, 3, 2, 1};
    displayBuiltInArray(n, 5);
    std::cout << fmt::format("std::begin returns: {}\n", fmt::ptr(std::begin(n))); // returns an iterator, not a pointer
    std::cout << fmt::format("print array name (address of the first element): {}\n", fmt::ptr(n));
    std::cout << fmt::format("std::end returns: {}\n", fmt::ptr(std::end(n)));
    std::cout << fmt::format("print address of the last element: {}\n", fmt::ptr(&n[4]));

    std::sort(std::begin(n), std::end(n));
    displayBuiltInArray(n, 5);
}