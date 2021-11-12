//
// Created by andy- on 2021-11-11.
//

#include <cstdio>

struct BaseClass {
    virtual ~BaseClass() = default;
};

struct DerivedClass : BaseClass {
    DerivedClass() {
        printf("DerivedClass() invoked.\n");
    }
    ~DerivedClass() override {
        printf("~DerivedClass() invoked.\n");
    }
};

int main() {
    printf("Constructing DerivedClass x.\n");
    BaseClass *x{new DerivedClass{}};
    printf("Deleting x as a BaseClass*.\n");
    delete x; // DerivedClass destructor will not be invoked
}

/*
 * Declaring virtual destructor is optional when declaring an interface, but beware. If you forge that you haven't
 * implemented a virtual destructor in the interface and accidentally do something like exp9, you can leak resources,
 * and compiler won't warn you.
 */