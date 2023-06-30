//
// Created by wbai on 6/28/2023.
//
#include <array>
#include <fmt/format.h>
#include <iostream>
#include <numeric>
#include <ranges>

int main() {
    auto showValues{
            [](auto &values, const std::string &message) {
                std::cout << fmt::format("{}: ", message);
                for (const auto &value: values) {
                    std::cout << fmt::format("{} ", value);
                }

                std::cout << '\n';
            }
    };

    // std::views::iota range adaptor returns a range
    auto values1{std::views::iota(1, 11)}; // iota is similar to the range() function in python; half-open range
    showValues(values1, "Generate integers 1-10");

    // filter
    auto values2{values1 | std::views::filter([](const auto& x) { return x % 2 == 0; })}; // lazy pipeline
    showValues(values2, "Filtering even integers");

    // transform
    auto values3{values2 | std::views::transform([](const auto& x) { return x * x; })};
    showValues(values3, "Mapping even integers to squares");

    // combine filter and mapping
    auto values4{
        // this resembles a pipeline
        values1 | std::views::filter([](const auto& x) { return x % 2 == 0; })
                | std::views::transform([](const auto& x) {return x * x;})
    };
    showValues(values4, "Square of even integers");

    // reducing a range pipeline with accumulate
    std::cout << fmt::format("Sum squares of even integers 2-10: {}\n",
                             std::accumulate(std::begin(values4), std::end(values4), 0));

    // filtering and mapping an existing container's elements
    constexpr std::array numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto values5{
        numbers | std::views::filter([](const auto& x) { return x % 2 == 0;})
                | std::views::transform([](const auto& x) { return x * x; })
    };
    showValues(values5, "Square of even integers in array numbers");
}