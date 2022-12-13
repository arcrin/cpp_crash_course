//
// Created by andy- on 2022-05-15.
//
#include <cstdint>
#include <cstdio>
#include <cstring>



int main(){
    uint32_t temp = ((uint32_t) (-1) & 0xfUL) - 4UL;
    printf("%d", temp);
}