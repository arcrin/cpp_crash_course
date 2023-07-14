//
// Created by wbai on 7/13/2023.
//
#include <iostream>

int main() {
    char color[]{"blue"};
    const char *colorPtr{"blue"}; // both are pointer to the first character
    char colorAlt[]{'b', 'l', 'u', 'e', '\0'}; // initializer list of individual characters,
                                               // and manually include the terminating '\0'

    std::cout << color << '\n';
    std::cout << colorPtr << '\n';
    std::cout << colorAlt << '\n';
}