//
// Created by andy- on 2023-04-09.
// using range-based for.
//
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
    std::array items{1, 2, 3, 4, 5};

    std::cout << "Items before modification: ";
    for (const int& item:items) {
        std::cout << fmt::format("{} ", item);
    }

    for (int& item: items) {
        item *= 2;
    }

    std::cout << "\nItems after modification: ";
    for (const int &item: items) {
        std::cout << fmt::format("{} ", item);
    }

    for (int runningTotal{0}; const int& item:items){
        runningTotal += item;
        std::cout << fmt::format("\nitem: {}, running total: {}", item, runningTotal);
    }
}
