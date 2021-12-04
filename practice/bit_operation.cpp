//
// Created by wbai on 12/1/2021.
//

#include <cstdint>
#include <cstdio>

int main() {
    int32_t* pInt;
    int32_t addr = 0;
    pInt = &addr;
    *pInt |= 1 << 0;
    *pInt &= (0 << 0);
    printf("%032x", *pInt);
}