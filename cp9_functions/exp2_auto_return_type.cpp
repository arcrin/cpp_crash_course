//
// Created by wbai on 11/23/2021.
//

/*
 * Two ways to declare the return-type of a function:
 *  1. (Primary) Lead a function declaration with the return type
 *  2. (Secondary) Let the compiler deduce the return type by using auto
 *
 *  It's better to always indicate what you are returning, because function declarations serve as documentation.
 *
 *  The primary use case for auto return type deduction is with function templates; usually together with decltype
 */

#include <cstdio>

template<typename X, typename Y>
auto add(X x, Y y) -> decltype((x + y)) { // decltype will determine the return type based on the evaluation of x + y,
                                          // and fixes it to the add function
    return x + y;
}

int main() {
    auto my_double = add(100., -10);
    printf("decltype(double + int) = double; %f\n", my_double);

    auto my_uint = add(100U, - 20);
    printf("decltype(uint + int) = uint; %u\n", my_uint);

    auto my_ulonglong = add(char{100}, 54'999'900ull);
    printf("decltype(char + ulonglong) = ulonglong; %llu", my_ulonglong);
}