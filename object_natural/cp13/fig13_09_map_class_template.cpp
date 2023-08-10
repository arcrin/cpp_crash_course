#include <iostream>
#include <fmt/format.h>
#include <map>

int main() {
    // create a map; duplicate keys are ignored
    std::map<int, double> pairs{{15, 2.7},
                                {30, 111.11},
                                {5,  1010.1},
                                {10, 22.22},
                                {25, 33.333},
                                {5,  77.54},
                                {20, 9.345},
                                {15, 99.3}};
    // walk through elements of pairs
    std::cout << "pairs contains:\nKey\tValue\n";
    for (const auto &pair: pairs) {
        std::cout << fmt::format("{}\t{}\n", pair.first, pair.second);
    }

    pairs[25] = 9999.99;
    pairs[40] = 8765.43;

    // walk through elements of pairs
    std::cout << "\nAfter updates, pairs contains:\nKey\tValue\n";
    for (const auto &pair: pairs) {
        std::cout << fmt::format("{}\t{}\n", pair.first, pair.second);
    }
}