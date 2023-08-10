#include <algorithm>
#include <fmt/format.h>
#include <iostream>
#include <iterator>
#include <set>

int main() {
    std::set doubles{2.1, 4.2, 9.5, 2.1, 3.7};

    std::ostream_iterator<double> output{std::cout, ", "};
    std::cout << "double contains: ";
    std::ranges::copy(doubles, output);

    auto p{doubles.insert(13.8)};
    std::cout << fmt::format("\n{} {} inserted\n", *(p.first), (p.second ? "was" : "was not"));
    std::cout << "doubles contains: ";
    std::ranges::copy(doubles, output);

    p = doubles.insert(9.5);
    std::cout << fmt::format("\n{} {} inserted\n", *(p.first), (p.second ? "was" : "was not"));
    std::cout << "doubles contains: ";
    std::ranges::copy(doubles, output);
    std::cout << "\n";
}