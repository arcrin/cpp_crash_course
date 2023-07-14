//
// Created by wbai on 6/29/2023.
//

#include <iostream>
#include <vector>
#include <stdexcept>
#include <ranges>

void outputVector(const std::vector<int> &items); // display the vector

void inputVector(std::vector<int> &items); // input values into the vector

int main() {
    std::vector<int> integers1(7);
    std::vector<int> integers2(10);

    std::cout << "Size of vector integers1 is " << integers1.size() << "\nvector after initialization: ";
    outputVector(integers1);

    std::cout << "Size of vector integers2 is " << integers2.size() << "\nvector after initialization: ";
    outputVector(integers2);

    std::cout << "\nEvaluating: integers1 != integers2\n";

    if (integers1 != integers2) {
        std::cout << "integers1 and integers2 are not equal\n";
    }

    //create vector integers3 using integers1 as an initializer
    std::vector integers3{integers1}; // copy constructor

    std::cout << "\nSize of vector integers3 is " << integers3.size() << "\nvector after initialization: ";
    outputVector(integers3);

    const size_t upperLimit = integers1.size();
    for (const int &value: std::views::iota(0, static_cast<int>(upperLimit))) {
        integers1.at(value) = value;
    }

    std::cout << "integers1 after iterative init: \n";
    outputVector(integers1);

    // input and print integers1 and integers2
    std::cout << "\nEnter 17 integers:\n";
    inputVector(integers1);
    inputVector(integers2);

    std::cout << "\nAfter input, the vectors contain:\n"
              << "integers1: ";
    outputVector(integers1);
    std::cout << "integers2: ";
    outputVector(integers2);


    // overloaded assignment operator
    std::cout << "\nAssigning integers2 to integers1:\n";
    integers1 = integers2;

    std::cout << "integers1: ";
    outputVector(integers1);
    std::cout << "integers2: ";
    outputVector(integers2);

    std::cout << "\nEvaluating: integers1 == integer2\n";

    if (integers1 == integers2) {
        std::cout << "integers1 and integers2 are equal\n";
    }
    integers1.at(1) = 2;
    std::cout << "Print integers1: \n";
    outputVector(integers1);
    std::cout << "Print integers2: \n";
    outputVector(integers2);

    // exception handling
    try {
        std::cout << "\nAttempt to display integers1.at(15)\n";
        std::cout << integers1.at(15) << '\n';
    }
    catch (const std::out_of_range &ex) {
        std::cout << "An exception occurred: " << ex.what() << '\n';
    }

    // changing the size of a vector
    std::cout << "\nCurrent integers3 size is: " << integers3.size();
    integers3.push_back(1000); // add 1000 to the end of the vector
    std::cout << "\nNew integers3 size is: " << integers3.size() << "\nintegers3 now contains: ";
    outputVector(integers3);
}

void outputVector(const std::vector<int> &items){
    for (const int &item: items) {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

void inputVector(std::vector<int> &items) {
    for (int &item: items) {
        std::cin >> item;
    }
}