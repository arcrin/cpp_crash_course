//
// Created by wbai on 4/4/2023.
// C++20 string formatting
//

#include <iostream>
#include <fmt/format.h> // C++20: This will be #include <format>
using namespace std;
using namespace fmt;

int main() {
    string student{"Paul"};
    int grade{87};

    cout << format("{}'s grade is {}\n", student, grade);
}