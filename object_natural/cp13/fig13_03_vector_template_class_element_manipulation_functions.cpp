#define FMT_HEADER_ONLY
#include <algorithm>
#include <fmt/format.h>
#include <iostream>
#include <ranges>
#include <iterator>
#include <vector>

int main() {
    std::vector values{1, 2, 3, 4, 5}; // class template argument deduction
    std::vector<int> integers{values.cbegin(), values.cend()};
    std::ostream_iterator<int> output{std::cout, " "};

    std::cout << "integers contains: ";
    std::copy(integers.cbegin(), integers.cend(), output);

    std::cout << fmt::format("\nfront: {}\nback: {}\n\n", integers.front(), integers.back());

    integers[0] = 7;
    integers.at(2) = 10;

    integers.insert(integers.cbegin() + 1, 22);

    std::cout << "Contents of vector integers after changes: ";
    std::ranges::copy(integers, output);

    integers.erase(integers.cbegin());
    std::cout << "\n\nintegers after erasing first element: ";
    std::ranges::copy(integers, output);

    // erase remaining elements
    integers.erase(integers.cbegin(), integers.cend());
    std::cout << fmt::format("\nErased all elements: integers {} empty\n",
                             integers.empty() ? "is" : "is not");

    // insert elements from the values vector
    integers.insert(integers.cbegin(), values.cbegin(), values.cend() - 1); // constant iterator overloads '-' operator
    std::cout << "\nContents of vector integers before clear: ";
    std::ranges::copy(integers, output);

    // empty integers; clear empties a collection
    integers.clear();
    std::cout << fmt::format("\nAfter clear, integers {} empty\n", integers.empty() ? "is" : "is not");
}