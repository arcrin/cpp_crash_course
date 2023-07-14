//
// Created by wbai on 7/5/2023.
//
#include <fmt/format.h>
#include <iostream>

size_t getSize(double *ptr);

int main() {
    int sample_int{1};
    int *sample_int_ptr{&sample_int};
    std::cout << fmt::format("Size of an int {}\n", sizeof(sample_int));
    std::cout << fmt::format("Size of an int pointer {}\n\n", sizeof(sample_int_ptr));

    double sample_double{1.0};
    double* sample_double_ptr{&sample_double};
    std::cout << fmt::format("Size of an int {}\n", sizeof(sample_double));
    std::cout << fmt::format("Size of an int pointer {}\n\n", sizeof(sample_double_ptr));

    double numbers[20];
    std::cout << fmt::format("Size of the double array {}\n", sizeof(numbers));
    std::cout << fmt::format("Size of the double array pointer {}\n\n", getSize(numbers)); // decay to a pointer
}

size_t getSize(double* ptr) {
    return sizeof(ptr);
}