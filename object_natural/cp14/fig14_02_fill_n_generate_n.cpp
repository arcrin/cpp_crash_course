#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

char nextLetter() {
    static char letter{'A'};
    return letter++;
}

int main() {
    std::array<char, 10> chars{};

    std::ranges::fill(chars, '5');

    std::cout << "chars after filling with 5s: ";
    std::ostream_iterator<char> output{std::cout, " "};
    std::ranges::copy(chars, output);

    // fill first five elements of chars with 'A's
    std::ranges::fill_n(chars.begin(), 5, 'A');

    std::cout << "\nchars after filling five elements with 'A's: ";
    std::ranges::copy(chars, output);

    // generate values for all elements of chars with nextLetter
    std::ranges::generate(chars, nextLetter);

    std::cout << "\nchars after generating letters A-J: ";
    std::ranges::copy(chars, output);

    std::ranges::generate_n(chars.begin(), 5, nextLetter);

    std::cout << "\nchars after generating K-O into elements 0-4: ";
    std::ranges::copy(chars, output);

    // generate values for first three elements of chars with a lambda
    std::ranges::generate_n(chars.begin(), 3,
                            [](){ static char letter{'A'};
                                return letter++; });

    std::cout << "\nchars after generating A-C into elements 0-2: ";
    std::ranges::copy(chars, output);
    std::cout << "\n";
}