// fig15_05
// Constrained multiply function template that allows
// only integers and floating-point values
#include <concepts>
#include <iostream>

template<typename T>
    requires std::integral<T> || std::floating_point<T> // this will provide better error message,
                                                        // but doesn't change the fact that both arguments need to be the same type
T multiply(T first, T second) { return first * second; }

int main() {
    std::cout << "Product of 5 and 3: " << multiply(5, 3)
              << "\nProduct of 7.25 and 2.0: " << multiply(7.25, 2.0) << "\n";

    std::string s1{"hi"};
    std::string s2{"bye"};
    auto result{multiply(s1, s2)};
}