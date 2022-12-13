//
// Created by wbai on 11/1/2021.
//

#include <cstdio>

int main(){
    int gettysburg{};
    printf("gettysburg: %d\n", gettysburg);
    int *gettysburg_address = &gettysburg;
    printf("&gettysburg: %p\n", gettysburg_address);
}