//
// Created by andy- on 2021-10-30.
//

#include <cstdio>

int main(){
    unsigned int a = 3669732608;
    printf("Yabba %x!\n", a);
    unsigned int b = 69;
//    int mit_zip_code = 02139; // won't compile, leading zero indicates this is an octal number, 9 is not
    printf("There are %u, %o leaves here.\n", b, b);
}