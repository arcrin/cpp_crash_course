//
// Created by andy- on 2021-11-21.
//

/*
 * template type alias allows you to define parameters to a template partially or fully; results in a
 * new template. Sounds like Python functool partial
 */

#include <cstdio>
#include <stdexcept>
// recall narrowing cast: cast a value into a type that occupies smaller memory size. e.g: float to int
template <typename To, typename From>
struct NarrowCaster {
    To cast(From value) const {
        const auto converted = static_cast<To>(value);
        const auto backwards = static_cast<From>(converted);
        if (value != backwards) throw std::runtime_error{ "Narrowed!" };
        return converted;
    }
};

template<typename From>
using short_caster = NarrowCaster<short, From>; // partially fix "short" as the To type

int main() {
    try {
        const short_caster<int> caster;
        const auto cyclic_short = caster.cast(142857);
        printf("cyclic_short: %d\n", cyclic_short);
    } catch (const std::runtime_error &e) {
        printf("Exception: %s\n", e.what());
    }
}


