//
// Created by wbai on 8/3/2023.
//
#include <utility>
#include <iostream>

int main() {
    int x = 42;
    int new_value = 100;

    // Exchange the value of x with new_value
    int previous_value = std::exchange(x, new_value);

    std::cout << "Previous value of x: " << previous_value << std::endl;
    std::cout << "Updated value of x: " << x << std::endl;
}