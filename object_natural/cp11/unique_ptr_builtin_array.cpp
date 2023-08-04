//
// Created by wbai on 8/2/2023.
//
#include <memory>
#include <fmt/format.h>
#include <iostream>

int main() {
    auto ptr{std::make_unique<int[]>(10)};
    ptr[2] = 7;
    for (int i{0}; i < 10; ++i) {
        std::cout << ptr[i] << '\n';
    }
}