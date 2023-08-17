//
// Created by wbai on 8/16/2023.
#include <concepts>
#include <iostream>

// Numeric concept aggregates std::integral and std::floating_point
template<typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// abbreviated function template with constrained auto
auto multiply(Numeric auto first, Numeric auto second) {
    return first * second;
}

int main() {
    std::cout << "Product of 5 and 3: " << multiply(5, 3)
              << "\nProduct of 7.25 and 2.0: " << multiply(7.25, 2.0)
              << "\nProduct of 5 and 7.25: " << multiply(5, 7.25) << "\n";
}