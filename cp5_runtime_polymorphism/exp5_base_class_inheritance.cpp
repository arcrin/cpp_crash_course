//
// Created by wbai on 11/9/2021.
//

struct BaseClass {};
struct DerivedClass : BaseClass {};
void are_belong_to_us(BaseClass& base) {};

int main() {
    DerivedClass derived;
    are_belong_to_us(derived);
}