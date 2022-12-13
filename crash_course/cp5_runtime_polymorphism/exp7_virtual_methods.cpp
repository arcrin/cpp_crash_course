//
// Created by andy- on 2021-11-10.
//

#include <cstdio>

/*
 * If you want to permit a derived class to override a base class's methods, you use the virtual keyword.
 * By adding virtual to a method's definition, you declare that a derived class's implementation should be used
 * if one is supplied. Within the implementation, you add the override keyword to the method's declaration
 */

struct BaseClass {
    virtual const char* final_message() const {
        return "We apologize for the incontinence.";
    }
};

struct DerivedClass : BaseClass {
    const char* final_message() const override {
        return "We apologize for the inconvenience.";
    }
};

int main() {
    BaseClass base;
    DerivedClass derived;
    BaseClass &ref = derived;
    printf("BaseClass:      %s\n", base.final_message());
    printf("DerivedClass:   %s\n", derived.final_message());
    printf("BaseClass&:     %s\n", ref.final_message());
}