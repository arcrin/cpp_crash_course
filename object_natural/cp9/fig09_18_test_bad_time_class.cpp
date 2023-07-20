//
// Created by wbai on 7/19/2023.
//
#include <iostream>
#include <fmt/format.h>
#include "BadTimeClass.h"

int main() {
    BadTimeClass t{};

    int &hourRef{t.badSetHour(20)};

    std::cout << fmt::format(
            "valid hour before modification: {}\n", hourRef
    );
    hourRef = 30;
    std::cout << fmt::format(
            "invalid hour after modification: {}\n\n", t.getHour()
    );
    t.badSetHour(12) = 74;

    std::cout << "After using t.badSetHour(12) as an lvalue, "
              << fmt::format("hour is: {}\n", t.getHour());
}