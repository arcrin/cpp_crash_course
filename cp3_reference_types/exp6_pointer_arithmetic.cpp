//
// Created by wbai on 11/1/2021.
//

#include <cstdio>

struct College {
    char name[256];
};

int main() {
    College oxford[] = {"Magdalen", "Nuffield", "Kellog"};
    College* third_college_ptr = &oxford[2];
    College* third_college_ptr_other = oxford + 2;
    printf("address of first element %p\n", &oxford);
    printf("3rd college %s\n", *third_college_ptr);
    printf("3rd college %s\n", *third_college_ptr_other);
}