//
// Created by wbai on 8/9/2023.
#include <iostream>
#include <exception>
#include <stdexcept>

class CustomException : public std::runtime_error {
public:
    CustomException() : std::runtime_error{"Custom Exception"} {}
};

// throw, catch and rethrow exception
void throwException() {
    // throw exception and catch it immediately
    try {
        std::cout << " Function throwException throws an exception\n";
        throw CustomException{}; // generate exception
    }
    catch (const CustomException& customException) { // handle exception
        std::cout << " Exception handled in function throwException"
                  << "\n Function throwException rethrows exception\n"
                  << customException.what() << '\n';
        throw; // rethrow exception for further processing
    }

    std::cout << "This should not print\n";
}

int main() {
    try{
        std::cout << "main invokes function throwException\n";
        throwException();
        std::cout << "This should not print\n";
    }
    catch (const CustomException& customException) {
        std::cout << "\n\nException handled in main\n"
        << customException.what() << '\n';
    }
    std::cout << "Program control continues after catch in main\n";
}