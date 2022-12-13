//
// Created by andy- on 2021-11-15.
//

#include <cstdio>

/*
 * The comma operator, on the other hand, doesn't usually promote cleaner code. It allows several expressions separated
 * by commas to be evaluated within a larger expression. The expressions evaluate from left to right, and the rightmost
 * expression is the return value
 */

int confusing(int &x) {
    return x = 9, x++, x / 2;
}

int main() {
    int x{};
    auto y = confusing(x);
    printf("x: %d\ny: %d", x, y);
}