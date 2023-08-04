//
// Created by wbai on 8/2/2023.
//
#include <iostream>
#include <span>

int main() {
    int *gradesArray{new int[10]{}};
    std::span gradesSpan(gradesArray, 10);
    for (const auto &number : gradesSpan) {
        std::cout << number;
    }
}