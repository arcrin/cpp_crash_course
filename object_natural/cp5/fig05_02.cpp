//
// Created by wbai on 2/6/2023.
//
#include <iostream>
#include <random>
using namespace std;

int main() {
    default_random_engine engine{};
    uniform_int_distribution randomDie{1, 6};
    for (int counter{1}; counter <= 10; ++counter) {
        cout << randomDie(engine) << " ";
    }
    cout << '\n';
}