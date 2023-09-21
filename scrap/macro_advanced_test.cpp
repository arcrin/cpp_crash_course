//
// Created by wbai on 9/19/2023.
//

#include <iostream>

/*
 * To prevent recursion, cpp associate a bit with every macro that has been defined.
 * The bit reflects whether the macro is currently being replaced with its substitution
 * list, we can call it replacing bit.
 * Cpp furthermore associates a bit with each token in the input stream, signifying that
 * the token can never be macro-expanded. Let's call the latter bit the unavailable bit.
 * Initially, the replacing bit and unavailable bits are all clear.
 *
 * As cpp processes each input token T, it sets T's unavailable bit and decides whether
 * to macro-expand -- because it's a function-like macro not followed by "(" -- cpp still
 * sets the unavailable bit. Moreover, once the unavailable has been set on an input token,
 * it is never cleared.
 */


/*
 * __VA_ARGS__ expands to all arguments passed to the macro,
 * separated by commas.
 * In C++20, it introduced __VA_OPT__. The sequence __VA_OPT__(x),
 * which is only legal in the substitution list of a variable-argument macro,
 * expands to x if __VA_ARGS__ is none-empty and to nothing if it is empty.
 */
#define LOG(fmt, ...) printf("[" fmt "]\n" __VA_OPT__(,) __VA_ARGS__)

/*
 * As an unintended benefit, differentiating between empty and non-empty
 * argument lists is exactly the mechanism we need to implement the
 * base case in recursion
 */

#define PARENS ()

#define EXPAND4(...) __VA_ARGS__
#define EXPAND3(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND2(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND1(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))

#define FOR_EACH(macro, ...)                                    \
    __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))

#define FOR_EACH_HELPER(macro, a1, ...)                         \
    macro(a1)                                                   \
    __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))

#define FOR_EACH_AGAIN() FOR_EACH_HELPER

#define ENUM_CASE(name) case name: return #name;

#define MAKE_ENUM(type, ...)                    \
enum type {                                     \
    __VA_ARGS__                                 \
};                                              \
constexpr const char * to_cstring(type _e) {    \
    using enum type;                            \
    switch (_e) {                               \
        FOR_EACH(ENUM_CASE, __VA_ARGS__)        \
        default:                                \
            return "unknown";                   \
    }                                           \
}

MAKE_ENUM(MyType, ZERO, ONE, TWO, THREE);

void test(MyType e) {
    std::cout << to_cstring(e) << " = " << e << std::endl;
}

int main() {
    test(ZERO);
    test(ONE);
    test(TWO);
    test(THREE);
}

