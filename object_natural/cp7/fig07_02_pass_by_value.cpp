//
// Created by wbai on 7/4/2023.
//
#include <fmt/format.h>
#include <iostream>

int cubeByValue(int n);

int main() {
    int number{5};

    std::cout << fmt::format("Original value of number is {}\n", number);
    number = cubeByValue(number); // pass number by value to cubeByValue
    std::cout << fmt::format("New value of number is {}\n", number);
}

// calculate and return cube of integer argument
int cubeByValue(int n) {
    return n * n * n;
}