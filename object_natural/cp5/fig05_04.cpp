//
// Created by wbai on 4/5/2023.
// randomizing the die-rolling program
//
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

int main() {
    unsigned int seed{0};

    cout << "Enter seed: ";
    cin >> seed;

    // set up random-number generation
    default_random_engine engine{seed};
    uniform_int_distribution randomDie{1, 6};

    // display 10 random die rolls
    for (int counter{1}; counter <= 10; ++counter) {
        cout << randomDie(engine) << " ";
    }
    cout << "\n";
}