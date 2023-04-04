//
// Created by wbai on 4/4/2023.
// logical operators
//
#include <iostream>
#include <fmt/format.h>

using namespace std;
using namespace fmt;

int main() {
    cout << "Logical AND (&&)\n"
         << format("false && false: {}\n", false && false)
         << format("false && true: {}\n", false && true)
            << format("true && false: {}\n", true && false)
            << format("true && true: {}\n\n", true && true);

    // create truth table for || (logical OR) operator
    cout << "Logical OR (||)\n"
         << format("false || false: {}\n", false || false)
         << format("false || true: {}\n", false || true)
         << format("true || false: {}\n", true || false)
         << format("true || true: {}\n\n", true || true);

    // create truth table for ! (logical negation) operator
    cout << "Logical negation (!)\n"
         << format("!false: {}\n", !false)
         << format("!true: {}\n", !true);
}
