//
// Created by andy- on 2021-10-31.
//

#include <cstdio>

struct Book{
    char name[256];
    int year;
    int pages;
    bool hardcover;
};

int main(){
    Book neuromancer{};
    neuromancer.pages = 271;
    printf("Neuromancer has %d pages.", neuromancer.pages);
}