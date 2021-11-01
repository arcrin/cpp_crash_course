//
// Created by andy- on 2021-10-31.
//

#include <cstddef>
#include <cstdio>

int main() {
    size_t size_c = sizeof(char);
    printf("char: %zu\n", size_c);
    size_t size_s = sizeof(short);
    printf("char: %zu\n", size_s); // decimal representation
    printf("char: %zx\n", size_s); // hex representation
    size_t size_i = sizeof(int);
    printf("char: %zu\n", size_i);
    size_t size_l = sizeof(long);
    printf("char: %zu\n", size_l);
    size_t size_ll = sizeof(long long);
    printf("long long: %zu\n", size_ll);
}