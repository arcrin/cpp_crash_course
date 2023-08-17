//
// Created by wbai on 8/16/2023.
#include <array>
#include <iostream>
#include <iterator>
#include <list>

// calculate the distance (number of items) between two iterators
// using input iterators; requires incrementing between iterators,
// so this is an O(n) operation
template <std::input_iterator Iterator>
auto customDistance(Iterator begin, Iterator end) {
    std::cout << "Called customDInstance with input iterators\n";
    std::ptrdiff_t count{0};

    // increment from begin to end and count number of iterations
    for (auto &iter{begin}; iter != end; ++iter) {
        ++count;
    }

    return count;
}

// calculate the distance (number of items) between two iterators
// using random-access iterators and an O(1) operation
template<std::random_access_iterator Iterator>
auto customDistance(Iterator begin, Iterator end) {
    std::cout << "Called customDistance with random-access iterators\n";
    return end - begin; // return a std::ptrdiff_t value
}

int main() {
    std::array ints1{1, 2, 3, 4, 5}; // has random-access iterators
    std::list ints2{1, 2, 3}; // has bidirectional iterators

    auto result1{customDistance(ints1.begin(), ints1.end())};
    std::cout << "ints1 number of elements: " << result1 << "\n";
    auto result2{customDistance(ints2.begin(), ints2.end())};
    std::cout << "ints2 number of elements: " << result2 << "\n";
}