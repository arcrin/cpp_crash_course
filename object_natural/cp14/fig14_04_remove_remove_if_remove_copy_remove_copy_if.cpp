#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector init{10, 2, 15, 4, 10, 6};
    std::ostream_iterator<int> output{std::cout, " "};

    std::vector v1{init};
    std::cout << "v1: ";
    std::ranges::copy(v1, output);

    // remove all 10s from v1
    auto removed{std::ranges::remove(v1, 10)};
    v1.erase(removed.begin(), removed.end());
    std::cout << "\nv1 after removing 10s: ";
    std::ranges::copy(v1, output);
}