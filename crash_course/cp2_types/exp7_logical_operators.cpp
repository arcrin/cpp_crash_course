//
// Created by andy- on 2021-10-31.
//

#include <cstdio>

int main() {
    bool t = true;
    bool f = false;
    printf("!true: %d\n", !t);
    printf("true && false: %d\n", t && f);
    printf("true && !false: %d\n", t && !f);
    printf("true || false: %d\n", t || f);
    printf("false || false: %d \n", f || f);
}