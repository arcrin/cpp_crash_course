//
// Created by wbai on 9/14/2023.
//
#include <fmt/format.h>
#include <iostream>
#define ENUM_CASE(name) case name: return #name;

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
    Color color = GREEN;
    const char *colorName = ColorToString(color);
    std::cout << fmt::format("Color: {}\n", colorName);
}