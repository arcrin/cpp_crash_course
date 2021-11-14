
//
// Created by wbai on 11/13/2021.
//

#include <cstdio>
#include <type_traits>
//#include <cstdint>

/*
 * Because "requires" expressions are evaluated at compile time, concepts can contain any number of them. Try to
 * construct a concept that guards against the misuse of mean.
 */
/*
 * template<typename T>
 * T mean(T* values, size_t length) {
 *     T result{};
 *     for (size_t i{}; i<length; i++) {
 *         result += values[i];
 *     }
 *     return result / length;
 * }
 *
 * There are three requirements implied by this code.
 * 1. T must be default constructible.
 * 2. T supports operator +=
 * 3. Dividing a T by size_t yields a T
 */

template<typename T>
concept bool Averageable() {
    return std::is_default_constructible<T>::value
    && requires (T a, T b) {
        { a += b } -> T;
        { a / size_t{ 1 } } -> T;
    };
}