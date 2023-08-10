#include <fmt/format.h>
#include <iostream>
#include <map>

int main() {
    std::multimap<int, double> pairs{};
    std::cout << fmt::format("Number of key(15) in pairs: {}\n", pairs.count(15));

    // insert two pairs
    pairs.insert(std::make_pair(15, 99.3));
    pairs.insert(std::make_pair(15, 2.7));
    std::cout << fmt::format("Number of key(15) in pairs: {}\n\n", pairs.count(15));

    // insert five pairs
    pairs.insert({30, 111.11});
    pairs.insert({10, 22.22});
    pairs.insert({25, 33.333});
    pairs.insert({20, 9.345});
    pairs.insert({5, 77.54});

    std::cout << "Multiple pairs contains: \nKey\tValue\n";

    // walk through elements of pairs
    for (const auto &mapItem: pairs) {
        std::cout << fmt::format("{}\t{}\n", mapItem.first, mapItem.second);
    }
}