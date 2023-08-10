//
// Created by wbai on 8/10/2023.
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>

int main() {
    std::deque<double> values; // create dqeu of doubles
    std::ostream_iterator<double> output{std::cout, " "};

    // insert elements in values
    values.push_front(2.2);
    values.push_front(3.5);
    values.push_back(1.1);

    std::cout << "values contains: ";

    // use subscript operator to obtain elements of values
    for (size_t i{0}; i < values.size(); ++i) {
        std::cout << values[i] << ' ';
    }

    values.pop_front();
    std::cout << "\nAfter pop_front, values contains: ";
    std::ranges::copy(values, output);

    // use subscript operator to modify element at location 1
    values[1] = 5.4;
    std::cout << "\nAfter values[1] = 5.4, values contains: ";
    std::ranges::copy(values, output);
    std::cout << "\n";
}