#include <algorithm>
#include <array>
#include <fmt/format.h>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>

int main() {
    std::array a1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array a2{a1};
    std::array a3{1, 2, 3, 4, 1000, 6, 7, 8, 9, 10};
    std::ostream_iterator<int> output{std::cout, " "};

    std::cout << "a1 contains: ";
    std::ranges::copy(a1, output);
    std::cout << "\na2 contains: ";
    std::ranges::copy(a2, output);
    std::cout << "\na3 contains: ";
    std::ranges::copy(a3, output);

    // compare a1 and a2 for equality
    std::cout << fmt::format("\n\na1 is equal to a2: {}\n", std::ranges::equal(a1, a2));

    // compare a1, and a3 for equality
    std::cout << fmt::format("a1 is equal to a3: {}\n", std::ranges::equal(a1, a3));

    // check for mismatch between a1 and a3
    auto location{std::ranges::mismatch(a1, a3)};
    std::cout << fmt::format("a1 and a3 mismatch at index {} ({} vs. {})\n",
                             (location.in1 - a1.begin()), *location.in1, *location.in2);

    std::string s1{"HELLO"};
    std::string s2{"BYE BYE"};

    // perform lexicographical comparison of s1 and s2
    std::cout << fmt::format("\"{}\" < \"{}\": {}\n", s1, s2, std::ranges::lexicographical_compare(s1, s2));
}