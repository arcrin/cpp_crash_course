//
// Created by wbai on 11/23/2021.
//

/*
 * Functional programming is a programming paradigm that emphasizes function evaluation and immutable data.
 *
 * You can pass a function pointer as a parameter.
 *
 * You cannot modify the pointed-to function, only invoke.
 *
 * you can use the address-of operator or function name as a pointer
 */

#include <cstdio>

float add(float a, int b){
    return a + b;
}

auto subtract(float a, int b) {
    return a - b;
}

int main() {
    const float first{100};
    const int second{20};

//    float (*operation)(float, int) {};
    using operation_func = float (*)(float, int); // Type aliases
    operation_func operation{};
    printf("operation initialized to 0x%p\n", operation);

    operation = &add; // address-of add function
    printf("&add = 0x%p\n", operation);
    printf("%g + %d = %g\n", first, second, operation(first, second));


    operation = subtract; // name of subtract function
    printf("&subtract = 0x%p\n", operation);
    printf("%g - %d = %g\n", first, second, operation(first, second));
}