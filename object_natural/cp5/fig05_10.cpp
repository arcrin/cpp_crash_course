//
// Created by wbai on 4/5/2023.
// unary scope resolution operator
//
#include <iostream>

using namespace std;

const int number{7}; // global variable named number

int main() {
    const double number{10.5}; // local variable named number

    cout << "Local double value of number = " << number
         << "\nGlobal int value of number = " << ::number << '\n';
}
