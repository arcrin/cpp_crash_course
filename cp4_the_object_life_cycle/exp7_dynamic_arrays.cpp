//
// Created by wbai on 11/4/2021.
//

/*
 * Dynamic arrays are arrays with dynamic storage duration.
 */

#include <cstdio>

int main() {
    // new MyType[n_elements] {init-list}
    int *my_int_array_ptr = new int[5]{1, 2, 3, 4, 5};
    printf("5th element %d", my_int_array_ptr[4]);
    delete[] my_int_array_ptr
}