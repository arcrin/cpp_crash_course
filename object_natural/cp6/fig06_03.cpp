//
// Created by andy- on 2023-04-09.
// using range-based for.
//
#include <fmt/format.h>
#include <iostream>
#include <array>

int main() {
    std::array items{1, 2, 3, 4, 5}; // type inferred as array<int, 5>

    //display items before modification
    std::cout << "items before modification: ";
    for (const int &item: items) { // item is a reference to a const int
        std::cout << fmt::format("{} ", item);
    }

    // multiply the elements of items by 2
    for (int &item: items) {
        item *= 2;
    }

    // display items after modification
    std::cout << "\nitems after modification: ";
    for (const int &item: items) {
        std::cout << fmt::format("{} ", item);
    }

    // sum elements of items using range-based for loop with initialization
    std::cout << "\n\ncalculating a running total of items' values:\n";
    for (int runningTotal{0}; const int& item : items) {
        runningTotal += item;
        std::cout << fmt::format("item: {}; running total: {}\n", item, runningTotal);
    }
}
