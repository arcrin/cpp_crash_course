//
// Created by wbai on 12/1/2021.
//

#include <cstdint>
#include <cstdio>

int main() {
    int32_t a = 0;
    a |= 1  << 2;
    printf("%032x", 1 << 2);
}