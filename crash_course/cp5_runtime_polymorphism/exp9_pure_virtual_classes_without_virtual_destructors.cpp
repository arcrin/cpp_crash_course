//
// Created by andy- on 2021-11-11.
//

/*
 * You achieve interface inheritance through deriving from base classes that contain only pure-virtual methods.
 * Such classes are referred to as pure-virtual classes. In C++, interfaces are always pure-virtual classes.
 * Usually, you add virtual destructors to interfaces. In some rare circumstances, it's possible to leak resources
 * if you fail to mark destructors as virtual.
 */

#include <cstdio>

struct BaseClass {};

struct DerivedClass : BaseClass {
    DerivedClass() {
        printf("DerivedClass() invoked.\n");
    }
    ~DerivedClass() {
        printf("~DerivedClass() invoked.\n");
    }
};

int main() {
    printf("Constructing DerivedClass x.\n");
    BaseClass *x{new DerivedClass{}};
    printf("Deleting x as a BaseClass*.\n");
    delete x; // DerivedClass destructor will not be invoked
}