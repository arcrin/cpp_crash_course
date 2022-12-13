//
// Created by wbai on 11/17/2021.
//

/*
 * Pointers can always be implicitly converted to void*
 */

#include <cstdio>

void print_addr(void* x) {
    printf("0x%p\n", x);
}

int main() {
    int x{};
    print_addr(&x);
    print_addr(nullptr);
}