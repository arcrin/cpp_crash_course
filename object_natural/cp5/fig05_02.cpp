//
// Created by wbai on 2/6/2023.
// producing random integers in the range 1 through 6
//

#include <iostream>
#include <random> // contains C++11 random-number generation features
using namespace std;

int main() {
    // engine that produces random numbers
    default_random_engine engine{};

    // distribution that produces the int values 1-6 with equal likelihood
    uniform_int_distribution randomDie{1, 6};

    // display 10 random die rolls
    for (int counter{1}; counter <= 10; ++counter) {
        cout << randomDie(engine) << " ";
    }
    cout << "\n";
}