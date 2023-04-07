//
// Created by wbai on 4/6/2023.
// iterative function factorial
//
#include <iostream>
#include <iomanip>
#include <fmt/format.h>

using namespace std;

long factorial(int number); //

int main() {
    for (int counter{0}; counter <= 10; ++counter) {
        cout << fmt::format("factorial({}): {}\n", counter, factorial(counter));
    }
}

long factorial(int number) {
    long result{1};
    for (int counter{number}; counter >= 2; --counter) {
        result *= counter;
    }
    return result;
}