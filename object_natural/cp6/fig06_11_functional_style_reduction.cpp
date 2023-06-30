//
// Created by wbai on 6/28/2023.
//
#include <array>
#include <fmt/format.h>
#include <iostream>
#include <numeric>

int main() {
    constexpr std::array integers{10, 20, 30, 40};
    std::cout << fmt::format("Total of array elements: {}\n",
                             std::accumulate(std::begin(integers), std::end(integers), 0));
}