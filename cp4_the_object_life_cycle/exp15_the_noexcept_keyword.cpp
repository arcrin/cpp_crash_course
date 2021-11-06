//
// Created by wbai on 11/5/2021.
//

#include <stdexcept>

/*
 * The keyword noexcept is another exception-related term you should know. You can and should, mark any function that
 * cannot possibly throw an exception noexcept.
 */
bool is_odd(int x) noexcept {
    return 1 == (x % 2);
}

/*
 * Functions marked noexcept make a rigid contract. When you're using a function marked noexcept, you can rest assure
 * that the function cannot throw an exception. In exchange, you must be extremely careful when you mark your own
 * function noexcept, since the compiler won't check for you. If your code throws an exception inside a function marked
 * noexcept, it's bad juju. The C++ runtime will call the function std::terminate, a function that by default will exit
 * the program via abort. Your program cannot recover:
 */
void hari_kari() noexcept {
    throw std::runtime_error{"Goodbye, cruel world."};
}

int main() {
    hari_kari();
}

/*
 * Marking a function noexcept enables some code optimizations that rely on the function's not being able to throw an
 * exception. Essentially,  the compiler is liberated to use move semantics, which may be faster
 */