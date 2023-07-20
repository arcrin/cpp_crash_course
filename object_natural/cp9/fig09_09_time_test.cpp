//
// Created by wbai on 7/19/2023.
//
#include <fmt/format.h>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include "Time.h"

void displayTime(std::string_view message, const Time &time) {
    std::cout << fmt::format("{}\n24-hour time: {}\n12-hour time: {}\n\n",
                             message, time.to24HourString(), time.to12HourString());
}

int main() {
    Time t{};

    displayTime("Initial time:", t);
    t.setTime(13, 27, 6);
    displayTime("After setTime:", t);

    try {
        t.setTime(99, 99, 99);
    }
    catch (const std::invalid_argument &e) {
        std::cout << fmt::format("Exception: {}\n\n", e.what());
    }

    // display t's value after attempting to set an invalid time
    displayTime("After attempting to set an invalid time:", t);
}