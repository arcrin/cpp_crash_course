//
// Created by andy- on 2021-11-06.
//


/*
 * You can communicate to the compiler that a function accepts lvalues or rvalues using lvalue references and rvalue
 * references. Up to this point in this book, every reference parameter has been an lvalue reference, and these are
 * denoted with a single &. You can als take a parameter by rvalue reference using &&.
 *
 * Fortunatelly, the compiler does an excellent job of determining whether an object is an lvalue or an rvalue. In fact,
 * you can define multiple functions with the same name but with different parameters, and the compiler will
 * automatically call the correct version depending on what arguments you provide when you invoke the function.
 */

#include <cstdio>

void ref_type_l(int &x) {
    printf("lvalue reference %d\n", x);
}

void ref_type_r(int &&x) {
    printf("rvalue reference %d\n", x);
}

int main() {
    auto x = 1;
    ref_type_l(x);
    ref_type_r(2);
    ref_type_r(x + 2);
}