//
// Created by wbai on 4/4/2023.
// C++17 if statements with initializers, reduce the scope of the variables
//
#include <iostream>

using namespace std;

int main() {
    if (int value{7}; value == 7) {
        cout << "value is " << value << "\n";
    } else {
        cout << "value is not 7; it is " << value << "\n";
    }


    if (int value{3}; value == 9) {
        cout << "value is " << value << "\n";
    } else {
        cout << "value is not 9; it is " << value << "\n";
    }
}