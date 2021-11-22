//
// Created by andy- on 2021-11-21.
//

/*
 * Declaration statements introduce identifiers, such as functions, templates, and namespaces, into your programs.
 * This section explores some new features of these familiar declarations, as well as type aliases, attributes, and
 * structured bindings.
 */

/*
 * There are two concepts: functions declaration and function definition.
 *
 * A function declaration specifies input and output types. It doesn't need to include parameter names. A function
 * declaration is optional. As long as the function is defined somewhere, the compiler will figure it out.
 *
 * A function can be a member function or a non-member function. In both cases, we can separate declaration and
 * definition.
 *
 * To define a member function, you may need to use scope resolution operator and the class name to avoid conflict.
 */

#include <cstdio>
#include <cstdint>

void randomize(uint32_t &);

struct RandomNumberGenerator {
    explicit RandomNumberGenerator(uint32_t seed)
    : iterations{}, number{seed} {}

    uint32_t next();

    [[nodiscard]] size_t get_iterations() const;
private:
    size_t iterations;
    uint32_t number;
};

int main() {
    RandomNumberGenerator rng{0x4c4347};
    while (rng.next() != 0x474343) {}
    printf("%zu\n", rng.get_iterations());

    size_t iterations{};
    uint32_t number{0x4c4347};
    while (number != 0x474343){
        randomize(number);
        ++iterations;
    }
    printf("%zu", iterations);
}

uint32_t RandomNumberGenerator::next() {
    ++iterations;
    number = 0x3FFFFFFF & (0x41C64E6D * number + 12345) % 0x80000000;
    return number;
}

size_t RandomNumberGenerator::get_iterations() const {
    return iterations;
}

void randomize(uint32_t &x) {
    x = 0x3FFFFFFF & (0x41C64E6D * x + 12345) % 0x80000000;
}

