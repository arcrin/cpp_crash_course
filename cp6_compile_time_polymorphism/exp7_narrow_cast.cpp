//
// Created by wbai on 11/12/2021.
//

/*
 * Narrowing is a loss in information. Think about converting from an int to a short. As long as the value of int fits
 * into a short, the conversion is reversible and no narrowing occurs. If the value of int is too big for short, the
 * conversion isn't reversible and results in narrowing. Following illustrates a custom static_cast that performs a
 * runtime check for narrowing.
 */

#include <stdexcept>
#include <cstdio>

template <typename To, typename From>
To narrow_cast(From value) {
    const auto converted = static_cast<To>(value);
    const auto backwards = static_cast<From>(converted);
    if(value != backwards) throw std::runtime_error{"Narrowed!"};
    return converted;
}

int main() {
    /*
     * Notice that you only need to provide a single template parameter, the return type, upon instantiation.
     * The compiler can deduce the "From" parameter based on usage.
     */
    int perfect{496};
    const auto perfect_short = narrow_cast<short>(perfect);
    printf("perfect_short: %d\n", perfect_short);
    try {
        int cyclic{142857};
        const auto cyclic_short = narrow_cast<short>(cyclic);
        printf("cyclic_short: %d\n", cyclic_short);
    } catch (const std::runtime_error& e) {
        printf("Exception: %s\n", e.what());
    }
}