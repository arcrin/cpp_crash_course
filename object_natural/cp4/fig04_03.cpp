//
// Created by wbai on 4/4/2023.
// summing integers with the for statement
//
#include <iostream>

using namespace std;

int main() {
    int total{0};

    for (int number{2}; number <= 20; number += 2) {
        total += number;
    }
    cout << "Sum is " << total << "\n";
}