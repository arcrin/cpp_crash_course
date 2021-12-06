//
// Created by andy- on 2021-12-05.
//

#include <cstdint>
#include <cstdio>

int main() {
    uint8_t temp{};
//    temp = 1 << (2 * 1);
//    temp = 2 * (1 << 1);
    temp = 0x3 << (2 * 1);
    printf("%d", temp);
}