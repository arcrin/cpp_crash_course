#include <iostream>
#include <fmt/format.h>

int main() {
    int arg1{};
    int arg2{};
    int arg3{};

    std::cout << "Enter three integers: \n";
    if (std::cin >> arg1 >> arg2 >> arg3) {
        std::cout << fmt::format("Values entered: {} {} {}\n", arg1, arg2, arg3);
    } else {
        std::cerr << "Invalid input. Please enter three integers.\n";
        // Clear the fail state and ignore any remaining input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}