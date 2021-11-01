//
// Created by andy- on 2021-10-31.
//

#include <cstdio>

union Variant {
    char string[10];
    int integer;
    double floating_point;
};

int main() {
    Variant v{};
    v.integer = 42;
    printf("The ultimate answer: \t%d\n", v.integer);
    v.floating_point = 2.7182818284;
    printf("Euler's number e: \t%f\n", v.floating_point);
    printf("Euler's number e: \t%d\n", v.integer);

}