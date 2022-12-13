//
// Created by wbai on 11/17/2021.
//

/*
 * Implicit type conversions can occur anywhere a particular type is called for, but you provide a different type.
 * These conversions occur in several contexts.
 *
 * "Binary Arithmetic Operators" on page 183 outlined so-called promotion rules. In fact, these are from of implicit
 * conversion. Whenever an arithmetic operation occurs, shorter integral types are promoted to int types. Integral
 * types can also be promoted to floating-point types during arithmetic operation. All of this happens in the
 * background. The result is that, in most situations, the type system simply gets out of your way, so you can focus
 * on programming logic.
 *
 * Unfortunately, in some situations, C++ is a bit overzealous in silently converting types. Consider the following
 * implicit conversion from a double to a uint_8.
 */

#include <cstdint>

int main() {
    auto x = 2.7182818284590452353602874713527L;
    uint8_t y = x; // Silent truncation
//    uint8_t z{x}; // Can't initialize, narrowing conversion(loss of information) is prevented by braced initialization

}