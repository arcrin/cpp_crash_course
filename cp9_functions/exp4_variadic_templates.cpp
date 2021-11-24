//
// Created by wbai on 11/23/2021.
//

/*
 * Variadic Templates
 *
 * function templates that accept variadic, same-typed arguments.
 *
 * declared with template parameter pack
 *
 * compile-time recursion
 */

#include <cstdio>

template <typename T>
constexpr T sum(T x){
    return x;
}

template<typename T, typename ... Args>
constexpr T sum(T x, Args... args){
    return x + sum(args...);
}

int main() {
    printf("The answer is %d.", sum(2, 4, 6, 8, 10, 12));
}