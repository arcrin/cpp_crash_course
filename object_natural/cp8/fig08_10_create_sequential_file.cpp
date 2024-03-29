#include <cstdlib> // exit function prototype
#include <fmt/format.h>
#include <fstream> // contains file stream processing types
#include <iostream>
#include <string>

int main() {
    // ofstream opens the file
    if (std::ofstream output{"clients.txt", std::ios::out}) {
        std::cout << "Enter the account, name, and balance.\n" << "Enter end-of-file to end input.\n?";

        int account;
        std::string name;
        double balance;

        // read account, name and balance from cin, then place in file
        while (std::cin >> account >> name >> balance) {
            output << fmt::format("{} {} {}\n", account, name, balance);
            std::cout << "? ";

            if (std::cin.fail()) {
                std::cerr << "Invalid input. Please enter integer account, string name, and numeric balance\n";
                std::exit(EXIT_FAILURE);
            }
        }


    }
    else {
        std::cerr << "File could not be opened\n";
        std::exit(EXIT_FAILURE);
    }
}