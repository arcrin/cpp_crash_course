//
// Created by wbai on 11/2/2021.
//

#include <cstdio>

int main() {
    int original = 100;
    int &original_ref = original;
    printf("Original: %d\n", original);
    printf("Reference: %d\n", original_ref);

    int new_value = 200;
    original_ref = new_value;   //this assignment does not reseat original_ref so that it points to new_value.
                                //Rather, it assigns the value of new_value to the object it points to (original)
    printf("Original: %d\n", original);
    printf("New Value: %d\n", new_value);
    printf("Reference: %d\n", original_ref);
}