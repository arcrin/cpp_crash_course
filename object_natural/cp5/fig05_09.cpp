//
// Created by wbai on 4/5/2023.
// using default arguments
//
#include <iostream>

using namespace std;

int boxVolume(int length = 1, int width = 1, int height = 1);

int main() {
    // no arguments--use default values for all dimensions
    cout << "The default box volume is: " << boxVolume();

    // specify length; default width and height
    cout << "\n\nThe volume of a box with length 10, \n"
         << "width 1 and height 1 is: " << boxVolume(10);

    // specify length and width; default height
    cout << "\n\nThe volume of a box with length 10, \n"
         << "width 5 and height 1 is: " << boxVolume(10, 5);

    // specify all arguments
    cout << "\n\nThe volume of a box with length 10,\n"
         << "width 5 and height 2 is: " << boxVolume(10, 5, 2)
         << "\n";
}

int boxVolume(int length, int width, int height) {
    return length * width * height;
}