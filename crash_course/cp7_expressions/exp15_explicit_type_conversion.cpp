//
// Created by wbai on 11/17/2021.
//

/*
 * Explicit type conversions are also called casts. The first port of call for conducting an explicit type conversion
 * is braced initialization {}. This approach has the major benefit of being fully type safe and non-narrowing. The use
 * of braced initialization ensures at compile time that only safe, well-behaved, non-narrowing conversions are allowed.
 */

#include <cstdio>
#include <cstdint>
#include <limits>

int main() {
    int32_t a = 100;
    int64_t b{a};
    if (a==b) printf("Non-narrowing conversion!\n");
    int32_t c{b}; // narrowing conversion caught by braced initialization
    int64_t d = std::numeric_limits<int64_t>::max();
    int32_t e(d); // compiler abides
    if (e != d) printf("Narrowing conversion!\n");
}