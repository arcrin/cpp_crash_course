//
// Created by wbai on 9/14/2023.
//
#include <fmt/format.h>
#include <iostream>
#define ENUM_CASE(name) case name: return #name;
#define OL 123              // Object like macro
#define FL(x) ((x) + 1)     // Function like macro
#define ID(arg) arg
#define PARENS ()
#define F_AGAIN() F
#define F() f F_AGAIN PARENS()

enum Color {RED, GREEN, BLUE};

const char* ColorToString(Color color) {
    switch (color) {
        ENUM_CASE(RED)
        ENUM_CASE(GREEN)
        ENUM_CASE(BLUE)
        default:
            return "Unknown";
    }
}

int main() {
//    Color color = GREEN;
//    const char *colorName = ColorToString(color);
//    std::cout << fmt::format("Color: {}\n", colorName);
}