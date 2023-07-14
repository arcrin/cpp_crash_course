//
// Created by wbai on 7/4/2023.
//
#include <iostream>
#include <fmt/format.h>

int sumElement(const int* values, size_t numberOfElements);

int main() {
    int c[5]; // c is a built-in array of 5 integers
    int n[5]{50, 20, 30, 10, 40};
    std::cout << fmt::format("Print array name: {} \n", fmt::ptr(n));
    std::cout << fmt::format("Print first element name: {}\n", fmt::ptr(&n[0]));

    int array_sum{0};
    for (int element: n) {
        std::cout << fmt::format("{} ", element);
        array_sum += element;
    }
    std::cout << '\n';

    std::cout << fmt::format("Array sums up to: {}\n", array_sum);

    std::cout << "Call sumElement function\n\n";
    std::cout << fmt::format("sum from function call: {}\n", sumElement(n, 5));
}

int sumElement(const int* values, size_t numberOfElements){ // the array decays to a point when being passed into function
    int array_sum{0};
    for (int i{0}; i < numberOfElements; i++) {
        array_sum += values[i];
    }
    return array_sum;
}
