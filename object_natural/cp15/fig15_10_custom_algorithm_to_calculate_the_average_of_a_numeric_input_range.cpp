//
// Created by wbai on 8/17/2023.
#include <algorithm>
#include <array>
#include <concepts>
#include <iostream>
#include <iterator>
#include <list>
#include <ranges>
#include <vector>

// concept for an input range containing integer or floating-point values
template<typename T>
concept NumericInputRange = std::ranges::input_range<T> &&
        (std::integral<typename T::value_type> || std::floating_point<typename T::value_type>);

// calculate the average of a NumericInputRange's elements
auto average(NumericInputRange auto const& range) {
    long double total{0};
    for (auto iter{range.begin()}; iter != range.end(); ++iter) {
        total += *iter; // dereference iterator and add value to total0
    }

    // divide total by the number of elements in range
    return total / std::ranges::distance(range);
}

int main() {
    std::ostream_iterator<int> outputInt(std::cout, " ");
    const std::array ints{1, 2, 3, 4, 5};
    std::cout << "array ints: ";
    std::ranges::copy(ints, outputInt);
    std::cout << "\naverage of ints: " << average(ints);

    std::ostream_iterator<double> outputDouble(std::cout, " ");
    const std::vector doubles{10.1, 20.2, 35.3};
    std::cout << "\n\nvector doubles: ";
    std::ranges::copy(doubles, outputDouble);
    std::cout << "\naverage of doubles: " << average(doubles);

    std::ostream_iterator<long double> outputLongDouble(std::cout, " ");
    const std::list longDoubles{10.1L, 20.2L, 35.3L};
    std::cout << "\n\nlist longDoubles: ";
    std::ranges::copy(longDoubles, outputLongDouble);
    std::cout << "\naverage of longDoubles: " << average(longDoubles) << "\n";
}