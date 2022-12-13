//
// Created by wbai on 11/13/2021.
//

/*
 * Concepts validate type parameters. Within concepts, you manipulate types to inspect their properties. You can hand
 * roll these manipulations, or you can use the type support library built into the stdlib. The library contains
 * 'utilities for inspecting type properties. These utilities are collectively called type traits. They are available
 * in the <type_traits> header and are part of the std namespace.
 *
 * Each type trait is a template class that takes a single template parameter, the type you want to inspect. You
 * extract the results using the template's static member value. This member equals true if the type parameter meets
 * the criteria; otherwise, it is false.
 */

#include <type_traits>
#include <cstdio>
#include <cstdint>

constexpr const char* as_str(bool x) { return x ? "True" : "False"; }

int main() {
    printf("%s\n", as_str(std::is_integral<int>::value));
    printf("%s\n", as_str(std::is_integral<const int>::value));
    printf("%s\n", as_str(std::is_integral<char>::value));
    printf("%s\n", as_str(std::is_integral<uint64_t>::value));
    printf("%s\n", as_str(std::is_integral<int&>::value));
    printf("%s\n", as_str(std::is_integral<int*>::value));
    printf("%s\n", as_str(std::is_integral<float>::value));
}

/*
 * Type traits are often the building blocks for a concept, but sometimes you need more flexibility. Type traits tell
 * you what types are, but sometimes you must also specify how the template will use them. For this, you use
 * requirements.
 */