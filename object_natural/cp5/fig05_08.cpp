//
// Created by wbai on 4/5/2023.
// passing arguments by value and by references
//
#include <iostream>

using namespace std;

int squareByValue(int number); // prototype (for value pass)
void squareByReference(int number); // prototype (for reference pass)

int main() {
    int x{2}; // value to square using squareByValue
    int z{4}; // value to square using squareByReference

    // demonstrate squareByValue
    cout << "x = " << x << " before squareByValue\n";
    cout << "Value returned by squareByValue: "
         << squareByValue(x) << endl;
    cout << "x = " << x << " after squareByValue\n";

    // demonstrate squareByReference
    cout << "z = " << z << " before squareByReference\n";
    squareByReference(z);
    cout << "z = " << z << " after squareByReference\n";
}


// squareByValue multiplies number by itself, stores the
// result in number and returns the new value of number
int squareByValue(int number) {
    return number += number; // caller's argument not modified
}

// squareByReference multiplies nymberRef by itself and stores the result
// in the variable to which numberRef refers in function main
void squareByReference(int numberRef) {
    numberRef *= numberRef; // caller's argument modified
}