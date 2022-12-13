//
// Created by wbai on 11/22/2021.
//

/*
 * Attributes apply implementation-defined features to an expression statement.
 */

#include <cstdio>
#include <stdexcept>


[[noreturn]] void pitcher() {
    throw std::runtime_error{"Knuckleball"};
}

int main() {
    try{
        pitcher();
    } catch (const std::exception &e) {
        printf("exception: %s\n", e.what());
    }
}