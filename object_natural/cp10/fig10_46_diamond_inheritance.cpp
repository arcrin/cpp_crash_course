//
// Created by wbai on 8/1/2023.
//
#define FMT_HEADER_ONLY
#include <iostream>

class Base {
public:
    virtual void print() const = 0; // pure virtual
};

class DerivedOne : public Base {
public:
    void print() const override { std::cout << "DerivedOne\n"; }
};

class DerivedTwo : public Base {
public:
    void print() const override { std::cout << "DerivedTwo\n"; }
};

class MultipleInheritance : public DerivedOne, public DerivedTwo {
public:
    void print() const override { DerivedTwo::print(); }
};

int main() {
    MultipleInheritance both{}; // instantiate a MultipleInheritance object
    DerivedOne one{}; // instantiate a DerivedOne object
    DerivedTwo two{}; // instantiate a DerivedTwo object
    Base* array[3]{}; // create an array of base-class pointers

//    array[0] = &both;
    array[1] = &one;
    array[2] = &two;

    for (int i{0}; i < 3; ++i) {
        array[i]->print();
    }
}