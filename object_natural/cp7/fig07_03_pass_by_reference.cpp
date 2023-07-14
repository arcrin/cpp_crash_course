//
// Created by wbai on 7/4/2023.
//
#include <fmt/format.h>
#include <iostream>

void cubeByReference(int *nPtr);

int main() {
    int number{5};

    std::cout << fmt::format("Original value of number is {}\n", number);
    cubeByReference(&number); // pass number address to cubeByReference
    std::cout << fmt::format("New value of number is {}\n", number);
}

// calculate cube of *nPtr; modifies variable in main
void cubeByReference(int *nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr;
}