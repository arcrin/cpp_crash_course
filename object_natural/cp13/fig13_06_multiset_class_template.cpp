#include <algorithm>
#include <fmt/format.h>
#include <iostream>
#include <iterator>
#include <ranges>
#include <set>
#include <vector>

int main() {
    std::multiset<int, std::less<int>> ints{};

    std::cout << fmt::format("15s in ints: {}\n", ints.count(15));

    std::cout << "\nInserting two 15s into ints\n";
    ints.insert(15);
    ints.insert(15);
    std::cout << fmt::format("15s in ints: {}\n\n", ints.count(15));

    // search for 15 and 20 ints; find returns an iterator
    for (int i: {15, 20}) {
        if (auto result{ints.find(i)}; result != ints.end()) {
            std::cout << fmt::format("Found {} in ints\n", i);
        }
        else {
            std::cout << fmt::format("Did not find {} in ints\n", i);
        }
    }

    // insert elements of vector values into ints
    const std::vector values{7, 22, 9, 1, 18, 30, 100, 22, 85, 13};
    ints.insert(values.cbegin(), values.cend());
    std::cout << "\nAfter insert, ints contains:\n";
    std::ranges::copy(ints, std::ostream_iterator<int>{std::cout, " "});

    // determine lower and upper bound of 22 in ints
    std::cout << fmt::format(
            "\n\nlower_bound(22): {}\nupper_bound(22): {}\n\n",
            *ints.lower_bound(22), *ints.upper_bound(22));

    // use equal_range to determine lower and upper bound of 22 in ints
    auto p{ints.equal_range(22)};
    std::cout << fmt::format(
            "lower_bound(22): {}\nupper_bound(22): {}\n",
            *(p.first), *(p.second)
    );
}