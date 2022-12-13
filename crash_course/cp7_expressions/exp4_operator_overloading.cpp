//
// Created by andy- on 2021-11-15.
//

/*
 * For each fundamental types, some portion of the operators covered in this section will be available. For
 * user-defined types, you can specify custom behavior for these operators by employing operator overloading.
 * To specify behavior for an operator in an user-defined class, simply name the method with the word operator
 * immediately followed by the operator; ensure that the return types and parameters match the types of the
 * operands you want to deal with.
 */

#include <stdexcept>
#include <cstdint>
#include <limits>
#include <cstdio>

struct CheckedInteger{
    CheckedInteger(unsigned int value) : value {value} {}
    CheckedInteger operator+(unsigned int other) const {
        CheckedInteger result{value + other};
        if (result.value < value) throw std::runtime_error{"Overflow!"};
        return result;
    }

    const unsigned int value;
};

int main() {
    CheckedInteger a{100};
    auto b = a + 200;
    printf("a + 200 = %u\n", b.value);
    try{
        auto c = a + std::numeric_limits<unsigned int>::max();
    } catch(const std::overflow_error& e) {
        printf("(a + max) Exception: %s\n", e.what());
    }
}