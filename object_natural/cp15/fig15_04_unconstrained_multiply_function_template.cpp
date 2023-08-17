//
// Created by wbai on 8/16/2023.
#include <iostream>

// The arguments and return value are of the same type T.
// Arguments are passed by value and the function returns a value.
// The return value of a function is a rvalue,
// this means type T needs to support "copy" or "move" function to be assigned to a lvalue
template<typename T>
T multiply(T first, T second) { return first * second; }

int main() {
    std::cout << "Product of 5 and 3: " << multiply(5, 3)
              << "\nProduct of 7.25 and 2.0: " << multiply(7.25, 2.0) << "\n";
}
