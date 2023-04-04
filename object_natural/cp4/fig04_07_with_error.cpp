//
// Created by wbai on 4/4/2023.
// C++17 statements with initialization
//
#include <iostream>

using namespace std;

int main() {
    if (int value{7}; value == 7) {
        cout << "value is " << value << "\n";
    } else {
        cout << "value is not 7; it is " << value << "\n";
    }

    if (int value{13}; value == 9) {
        cout << "value is " << value << "\n";
    } else {
        cout << "value is not 9; it is " << value << "\n";
    }
    cout << value;
}
