#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include <ranges>
#include <vector>

// display value appened to vector and updated vector size and capacity
void showResult(int value, size_t size, size_t capacity) {
    std::cout << fmt::format("appended: {}; size: {}; capacity: {}\n", value, size, capacity);
}

int main() {
    std::vector<int> integers{}; // zero initialize

    std::cout << "Size of integers vector: " << integers.size()
              << "\nCapacity of integers: " << integers.capacity() << "\n\n";

    // append 1-10 to integers and display updated size and capacity
    for (int i: std::views::iota(1, 11)) {
        integers.push_back(i); // push_back is in vector, deque and list
        showResult(i, integers.size(), integers.capacity());
    }

    std::cout << "\nOutput integers vector using iterators: ";

    for (auto constIterator{integers.cbegin()}; constIterator != integers.cend(); ++constIterator) {
        std::cout << *constIterator << ' ';
    }

    std::cout << "\nOutput integers in reverse using iterators: ";

    // display vector in reverse order using const_reverse_iterator
    for (auto reverseIterator{integers.crbegin()}; reverseIterator != integers.crend(); ++reverseIterator) {
        std::cout << *reverseIterator << ' ';
    }

    std::cout << "\n";
}
