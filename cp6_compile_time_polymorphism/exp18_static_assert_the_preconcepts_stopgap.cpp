//
// Created by andy- on 2021-11-14.
//

#include <type_traits>
#include <cstdint>

template <typename T>
T mean(T* values, std::size_t length) {
    static_assert(std::is_default_constructible<T>(),
                  "Type must be default constructible.");
    static_assert(std::is_copy_constructible<T>(),
                  "Type must be copy constructible.");
    static_assert(std::is_arithmetic<T>(),
                  "Type must support addition and division");
    static_assert(std::is_constructible<T, size_t>(),
                  "Type must be constructible from size_t");
}

/*
 * Using static_assert as a proxy for concepts is a hack, but it's widely used. Using type traits, you can limp along
 * until concepts are included in the standard. You will often see static_assert if you use modern third-party
 * libraries; if you are writing code for others, consider using static_assert and type traits.
 */