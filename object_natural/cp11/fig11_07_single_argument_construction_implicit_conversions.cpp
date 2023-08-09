//
// Created by andy- on 2023-08-05.
#include <iostream>
#include "MyArray.h"


void outputArray(const MyArray&);

int main() {
    MyArray ints1(7); // 7-element MyArray
    outputArray(ints1); // output MyArray ints1
    outputArray(3); // convert 3 to a MyArray and output the contents
}

// print MyArray contents
void outputArray(const MyArray& arrayToOutput) {
    std::cout << "The MyArray received has " << arrayToOutput.size()
              << " elements. The contents are: " << arrayToOutput << '\n';
}