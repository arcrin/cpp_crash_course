//
// Created by wbai on 8/9/2023.
//
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include "DivideByZeroException.h"

// performs division only if the denominator is not zero;
// otherwise, throws DivideByZeroException object
double quotient(double numerator, double denominator) {
    // throw DivideByZeroException if trying to divide by zero
    if (denominator == 0.0) {
        throw DivideByZeroException{};
    }

    return numerator / denominator;
}

int main() {
    int number1{0};
    int number2{0};
//    int number3{3 / 0}; // this doesn't halt compilation
//    std::cout << number3;

    std::cout << "Enter two integers (end-of-file to end)";


    // enable user to enter two integers to divide
    while (std::cin >> number1 >> number2) {
        // try block contains code that might throw exception
        // and code that will not execute if an exception occurs
        try {
            double result{quotient(number1, number2)};
            std::cout << fmt::format("The quotient is: {}\n", result);
        }
        catch (const DivideByZeroException& divideByZeroException) {
            std::cout << fmt::format("Exception occurred: {}\n", divideByZeroException.what());
        }

        std::cout << "\nEnter two integers (end-of-file to end): ";
    }
    std::cout << '\n';
}