//
// Created by wbai on 9/14/2023.
//
#include <iostream>
#include <string>

#define PARENS ()

// Rescan macro tokens 256 times
#define EXPAND(arg) EXPAND1(EXPAND1(EXPAND1(EXPAND1(arg))))
#define EXPAND1(arg) EXPAND2(EXPAND2(EXPAND2(EXPAND2(arg))))
#define EXPAND2(arg) EXPAND3(EXPAND3(EXPAND3(EXPAND3(arg))))
#define EXPAND3(arg) EXPAND4(EXPAND4(EXPAND4(EXPAND4(arg))))
#define EXPAND4(arg)

#define FOR_EACH(macro, ...)                                \
    __VA_OPT__(EXPAND(FOR_EACH(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...)                     \
    macro(a1)                                               \
    __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER

#define ENUM_CASE(name) case name: return #name;

#define PRINT_VALUES(...) std::cout << __VA_ARGS__ << std::endl

#define MAKE_ENUM(type, ...)            \
enum type {                             \
    __VA_ARGS__                         \
};                                      \
constexpr const char *                  \
to_cstring(type _e)                     \
{                                       \
    using enum type;                    \
    switch (_e) {                       \
    FOR_EACH(ENUM_CASE, __VA_ARGS__)    \
    default:                            \
        return "unknown";               \
    }                                   \
}

MAKE_ENUM(MyType, ZERO, ONE, TWO, THREE);

void
test(MyType e)
{
    std::cout << to_cstring(e) << "=" << e << std::endl;
}

#if 0
int main() {
    test(ZERO);
    test(ONE);
    test(TWO);
    test(THREE);

    int x = 10;
    double y = 3.14;
    std::string s = "hello";

    PRINT_VALUES(x, y, s);
}
#endif

#if 1
int main() {
    int x = 10;
    double y = 3.14;
    std::string s = "hello";

    PRINT_VALUES(x, y, s);

    return 0;
}
#endif