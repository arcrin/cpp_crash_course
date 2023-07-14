#include <fmt/format.h>
#include <iostream>
#include <string>

// display string statistics
void printStatistics(const std::string& s) {
    std::cout << fmt::format(
            "capacity: {}\nmax size: {}\nsize: {}\nempty: {}",
            s.capacity(), s.max_size(), s.size(), s.empty()
    );
}

int main() {
    std::string string1; // empty string
    std::cout << "Statistics before input: \n";
    std::cin >> string1; // delimited by whitespace
    std::cout << fmt::format("The string entered was: {}\n", string1);
    std::cout << "Statistics after input: \n";
    printStatistics(string1);
}