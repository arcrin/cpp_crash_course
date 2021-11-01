//
// Created by andy- on 2021-10-30.
//

#include <cstdio>

int main() {
    char x ='M';
    wchar_t y = L'Z';
    printf("Windows binaries start with %c%lc.\n", x, y);
    printf("Windows binaries start with \u0041 \U0001F37A .\n");
}