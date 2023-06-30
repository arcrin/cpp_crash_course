//
// Created by wbai on 6/28/2023.
//

#include <iostream>

int main() {
    char str[] = "123\n"; // or char* str = "123\n"
    std::cout << "Before modification\n";
    std::cout << str;
    str[0] = '2';
    std::cout << "After modification\n";
    std::cout << str;
}