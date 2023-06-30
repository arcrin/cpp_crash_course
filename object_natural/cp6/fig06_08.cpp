//
// Created by wbai on 6/27/2023.
//
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
    constexpr std::array responses{
            1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5
    };
    constexpr size_t frequencyArraySize{6}; // ignore response 0
    std::array<int, frequencyArraySize> frequency{};

    for (const int &response: responses) {
        ++frequency.at(response);
    }
    std::cout << fmt::format("{}{:>12}\n", "Rating", "Frequency");

    for (size_t rating{1}; rating < frequency.size(); ++rating) {
        std::cout << fmt::format("{:>6}{:12}\n", rating, frequency.at(rating));
    }
}