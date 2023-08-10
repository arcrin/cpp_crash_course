//
// Created by wbai on 8/9/2023.
#include <iostream>
#include <stdexcept>

// function3 throws runtime error
void function3() {
    std::cout << "In function 3\n";

    // no try block, stack unwinding occurs, return control to function2
    throw std::runtime_error{"runtime_error in function3"};
}

// function2 invokes function3
void function2() {
    std::cout << "function3 is called inside function2\n";
    function3(); // stack unwinding occurs, return control to function1
}

// function1 invokes function2
void function1() {
    std::cout << "function2 is called inside function1\n";
    function2(); // stack unwinding occurs, return control to main
}

int main() {
    // invoke function1
//    try {
//        std::cout << "function1 is called inside main\n";
//        function1(); // call function1 which throws runtime_error
//    }
//    catch (const std::runtime_error& error) { // handle runtime error
//        std::cout << "Exception occurred: " << error.what()
//                  << "\nException handled in main\n";
//    }
        std::cout << "function1 is called inside main\n";
        function1(); // call function1 which throws runtime_error
}