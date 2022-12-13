//
// Created by andy- on 2021-11-15.
//

/*
 * The ternary conditional operator
 * x ? y : z
 */

#include <cstdio>

int step(int input) {
    return input > 0 ? 1 : 0;
}

int main() {
    printf("%d", step(2));
}