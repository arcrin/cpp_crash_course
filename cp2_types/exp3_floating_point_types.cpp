//
// Created by andy- on 2021-10-30.
//

#include <cstdio>

int main() {
    double an = 6.0221409e23;
    printf("Avogadro's Number: %le %lf %lg\n", an, an, an);
    float hp = 9.75;
    printf("Hodwarts' Platform: %e %f %g\n", hp, hp, hp); // as a general rule, use %g to print floating point numbers
}