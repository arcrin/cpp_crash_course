//
// Created by wbai on 11/23/2021.
//

/*
 * Overload Resolution
 *
 * Matching a function invocation with its proper implementation.
 */

/*
 * Variadic Functions
 *
 * a function that takes a variable number of arguments. Example, printf.
 *
 * declared with ... as the final parameter.
 */

#include <cstdio>
#include <cstdint>
#include <cstdarg>

int sum(size_t n, ...) {
    va_list args;
    va_start(args, n);
    int result{};
    while (n--) {
        auto next_element = va_arg(args, int);
        result += next_element;
    }
    va_end(args);
    return result;
}

int main() {
    printf("The answer is %d.", sum(6, 2, 4, 6, 8, 10, 12));
}

/*
 * problems with variadic function:
 *  1. not type safe
 *  2. size of variadic argument-list needs to be tracked separately
 */