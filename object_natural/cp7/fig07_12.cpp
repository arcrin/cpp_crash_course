//
// Created by wbai on 7/5/2023.
//
#include <array>
#include <fmt/format.h>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>

// items parameter is treated as a const int* so we also need the size to
// know how to iterate over items with counter-controlled iteration
void displayArray(const int items[], size_t size) {
    for (size_t i{0}; i < size; ++i) {
        std::cout << fmt::format("{} ", items[i]);
    }
}

// span parameter contains both the location of the first item
// and the number of elements, so we can iterate using range-based for
void displaySpan(std::span<const int> items) {
    for (const auto& item : items) {
        std::cout << fmt::format("{} ", item);
    }
}

// spans can be used to modify elements in the original data structure
void times2(std::span<int> items) {
    for (int &item: items) {
        item *= 2;
    }
}


int main() {
    int values1[]{1, 2, 3, 4, 5};
    std::array values2{6, 7, 8, 9, 10};
    std::vector values3{11, 12, 13, 14, 15};

    // must specify size because the compiler treats displayArray's items
    // parameter as a pointer to the first element of the argument
    std::cout << "display array: ";
    displayArray(values1, 5);

    std::cout << "\ndisplay array via span: ";
    displaySpan(values1);

    std::cout << "\ndisplay std::array via span:  ";
    displaySpan(values2);

    std::cout << "\ndisplay std::vector via span: ";
    displaySpan(values3);

    times2(values1);
    std::cout << "\ndisplay array after times2 modification: ";
    displayArray(values1, 5);
    std::cout << "\ndisplay array via span after times2 modification: ";
    displaySpan(values1);

    // modify values in std::array
    times2(values2);
    std::cout << "\ndisplay std::array after times2 modification: ";
    displaySpan(values2);

    // modify values in std::vector
    times2(values3);
    std::cout << "\ndisplay std::vector after times2 modification: ";
    displaySpan(values3);

    // span object
    std::span mySpan{values1};
    std::cout << "\n\nmySpan's first element: " << mySpan.front()
              << "\nmySpan's last element: " << mySpan.back();

    // apply standard library algorithm on span
    std::cout << "\n\nSum of mySpan's elements: "
              << std::accumulate(std::begin(mySpan), std::end(mySpan), 0);

    // subviews of a container
    std::cout << "\n\nFirst three elements of mySpan: ";
    displaySpan(mySpan.first(3));
    std::cout << "\n\nLast three elements of mySpan: ";
    displaySpan(mySpan.last(3));
    std::cout << "\n\nMiddle three elements of mySpan: ";
    displaySpan(mySpan.subspan(1, 3));

    // changing a subview elements modifies the original data
    times2(mySpan.subspan(1, 3));
    std::cout << "\n\nvalues1 after times2 modification: ";
    displayArray(values1, 5);

    std::cout << "\n\ndisplay mySpan: ";
    displaySpan(mySpan);

    // access a span element via [] operator
    std::cout << "\n\nthe element at index 2 is: " << mySpan[2];
}