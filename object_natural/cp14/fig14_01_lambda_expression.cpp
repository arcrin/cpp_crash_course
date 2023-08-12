#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

int main() {
    std::array values{1, 2, 3, 4};
    std::ostream_iterator<int> output{std::cout, " "};

    std::cout << "values contains: ";
    std::ranges::copy(values, output);

    std::cout << "\nDisplay each element multiplied by two: ";
    std::ranges::for_each(values, [](auto i) { std::cout << i * 2 << " "; });

    int sum{0};
    std::ranges::for_each(values, [&sum](auto i) { sum += i; });
    std::cout << "\nSum of value's elements is: " << sum << "\n";
}