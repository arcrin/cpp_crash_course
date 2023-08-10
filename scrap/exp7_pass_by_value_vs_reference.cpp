//
// Created by wbai on 8/9/2023.
//
#define FMT_HEADER_ONLY
#include <iostream>
#include <fmt/format.h>

void passByValue(int x) {
    x = 20;
}

void passByReference(int &x) {
    x = 30;
}

int main() {
    int num = 10;

    std::cout << fmt::format("Before pass by value: {}\n", num);
    passByValue(num);
    std::cout << fmt::format("After pass by value: {}\n", num);

    std::cout << fmt::format("Before pass by reference: {}\n", num);
    passByReference(num);
    std::cout << fmt::format("After pass by reference: {}\n", num);
}