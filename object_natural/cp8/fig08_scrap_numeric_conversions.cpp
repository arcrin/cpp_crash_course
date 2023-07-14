#include <iostream>
#include <string>
#include <fmt/format.h>

int main() {
    std::string s{"1"};
    int i{1};
    std::cout << std::to_string(i);
    std::cout << '\n';

    if (s == std::to_string(i)) {
        std::cout << "match";
    } else {
        std::cout << "not match";
    }
}