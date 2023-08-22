// fig15_12.cpp
// Using MyArray with range-based for and with
// C++ standard library algorithm
#include <iostream>
#include <iterator>
#include "MyArray.h"

int main() {
    std::ostream_iterator<int> outputInt{std::cout, " "};
    std::ostream_iterator<double> outputDouble{std::cout, " "};
    std::ostream_iterator<std::string> outputString{std::cout, " "};

    std::cout << "Displaying MyArrays with std::range::copy, "
              << "which requires input iterators:\n";
    MyArray ints{1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "ints: ";
    std::ranges::copy(ints, outputInt);

    MyArray doubles{1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "ints: ";
    std::ranges::copy(doubles, outputDouble);

    using namespace std::string_literals;
    MyArray strings{"red"s, "orange"s, "yellow"s};
    std::cout << "\nstrings: ";
    std::ranges::copy(strings, outputString);

    std::cout << "\n\nDisplaying a MyArray with a range-based for "
              << "statement, which requires input iterators:\n";
    for (const auto &item: doubles) {
        std::cout << item << " ";
    }

    std::cout << "\n\nCopying a MyArray with std::ranges::copy, "
              << "which requires an input range and an output iterator:\n";
    MyArray<std::string, strings.size()> strings2{};
    std::ranges::copy(strings, strings2.begin());
    std::cout << "strings2 after copying from strings: ";
    std::ranges::copy(strings2, outputString);

    std::cout << "\n\nFinding min and max elements in a MyArray"
              << "with std::ranges::minmax_element, which requires "
              << "a forward range:\n";
    auto [min, max] {std::ranges::minmax_element(strings)};
    std::cout << "min and max elements of strings are: "
              << *min << ", " << *max;

    std::cout << "\n\nReversing a MyArray with std::ranges::reverse, "
              << "which requires a bidirectional range:\n";
    std::ranges::reverse(ints);
    std::cout << "ints after reversing elements: ";
    std::ranges::copy(ints, outputInt);
    std::cout << "\n";
}