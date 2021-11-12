//
// Created by andy- on 2021-11-11.
//

#include <cstdio>

/*
 * If you want to require a derived class to implement the method, you can append the =0 suffix to a method definition.
 * You call methods with both the virtual and =0 suffix pure virtual methods. You can't instantiate a class containing
 * any pure virtual methods.
 */


struct BaseClass {
    virtual const char *final_message() const = 0;
};

struct DerovedClass: BaseClass {
    const char* final_message() const override {
        return "We apologize for the inconvenience.";
    }
};

int main() {
//    BaseClass base; // can not instantiate
    DerovedClass derived;
    BaseClass &ref = derived;
    printf("DerivedClass:   %s\n", derived.final_message());
    printf("BaseClass&:     %s\n", ref.final_message());
}