//
// Created by wbai on 11/23/2021.
//

/*
 * fold expression applies a binary operation over all arguments of a parameter pack
 */

#include <cstdio>

template<typename... T>
constexpr auto sum(T... args) {
    return (... + args);
}

int main() {
    printf("The answer is %d.\n", sum(2, 4, 6, 8, 10, 12));
    printf("The answer is %f.", sum(2.0, 4, 6, 8, 10, 12));
}

