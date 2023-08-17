//
// Created by wbai on 8/16/2023.
//
#include <array>
#include <iostream>
#include <string>
#include <vector>

// abbreviated function template printContainer displays a
// container's elements separated by spaces
void printContainer(const auto &items) {
    for (const auto &item: items) {
        std::cout << item << " ";
    }
}

int main() {
    using namespace std::string_literals; // for string object literals

    std::array ints{1, 2, 3, 4, 5};
    std::vector strings{"red"s, "green"s, "blue"s};

    std::cout << "ints: ";
    printContainer(ints);
    std::cout << "\nstrings: ";
    printContainer(strings);
    std::cout << "\n";
}