//
// Created by wbai on 11/9/2021.
//

struct BaseClass {};
struct DerivedClass : BaseClass {};
void are_belong_to_us(BaseClass& base) {}
void all_about_that(DerivedClass& base) {}

int main() {
    BaseClass base;
    DerivedClass derived;
    are_belong_to_us(derived); // can treat derived class references as if they were of base class reference type
    all_about_that(base); // can not use base class in place of a derived class
}