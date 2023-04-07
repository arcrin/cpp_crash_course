//
// Created by wbai on 4/5/2023.
// function template
//
#include <iostream>
#include "maximum.h"

using namespace std;

int main() {
    // demonstrate maximum with int values
    cout << "Input three integer values: ";
    int int1, int2, int3;
    cin >> int1 >> int2 >> int3;

    // invoke int version of maximum
    cout << "The maximum integer value is: "
         << maximum(int1, int2, int3);

    //double values
    cout << "\n\nInput three double values: ";
    double double1, double2, double3;
    cin >> double1 >> double2 >> double3;

    // invoke double version of maximum
    cout << "The maximum double value is: "
         << maximum(double1, double2, double3);

    // char values
    cout << "\n\nInput three characters: ";
    char char1, char2, char3;
    cin >> char1 >> char2 >> char3;

    // invoke char version of maximum
    cout << "The maximum character value is: "
         << maximum(char1, char2, char3) << '\n';
}
