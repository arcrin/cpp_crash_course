//
// Created by andy- on 2021-10-31.
//

#include <cstdio>

struct Earth {
    ~Earth() {
        // Earth's destructor
        printf("Making way for hyperspace bypass");
    }
};