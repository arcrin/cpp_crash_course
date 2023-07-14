//
// Created by wbai on 7/4/2023.
//
#include <iostream>
#include <fmt/format.h>

int main() {
    // a non-constant pointer to non-constant data
    int a{0};
    int *aPtr{&a};
    *aPtr = 1;
    std::cout << fmt::format("variable \'a\' after modification: {}\n", a);
    // a non-constant pointer to constant data
    const int b{0};
    const int c{1};
    const int *bPtr{&b}; // pointer declaration; non-const pointer, const data
//    int const *bPtr{&b}; // can be written in this format
    bPtr = &c;
    std::cout << fmt::format("de-referenced bPtr after re-assigning pointer: {}\n", *bPtr);

    // a constant pointer to non-constant data
    int x;
    int *const xPtr{&x}; // pointer declaration; const pointer, non-const data
    *xPtr = 1;
    std::cout << fmt::format("value of \'x\' after assignment through de-referencing pointer\n");

    // a constant pointer to constant data
    int y{6};
    int z{7};
    const int *const yPtr{&y};
//    *yPtr = 10; //error
//    yPtr = &z; // error
}