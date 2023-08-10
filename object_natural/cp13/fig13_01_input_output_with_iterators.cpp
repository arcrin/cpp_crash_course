#include <iostream>
#include <iterator>

int main() {
    std::cout << "Enter two integers: ";

    // create istream_iteator for reading int values from cin
    std::istream_iterator<int> inputInt{std::cin};

    const int number1{*inputInt}; // read int from standard input
    ++inputInt; // move iterator to next input value
    const int number2{*inputInt}; // read int from standard input

    // create ostream_iterator for writing int values to cout
    std::ostream_iterator<int> outputInt{std::cout};

    std::cout << "The sum is: ";
    *outputInt = number1 + number2; // output result to cout
    std::cout << "\n";
}