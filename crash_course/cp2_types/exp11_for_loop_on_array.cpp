//
// Created by andy- on 2021-10-31.
//

#include <cstdio>
#include <cstdio>

int main() {
    unsigned long maximum = 0;
    unsigned long values[] = {10, 50, 20, 40, 0};
    for(size_t i=0;i < 5; i++){
        if(values[i] > maximum) maximum = values[i];
    }
    printf("The maximum value is %lu", maximum);
}