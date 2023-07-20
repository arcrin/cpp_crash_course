//
// Created by wbai on 7/19/2023.
//
#include <fmt/format.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Time.h"

// display a Time in 24-hour and 12-hour formats
void displayTime(std::string_view message, const Time &time) {
    std::cout << fmt::format("{}\n24-hour time: {}\n12-hour time: {}\n\n",
                             message, time.to24HourString(), time.to12HourString());
}

int main() {
    const Time t1{}; // this is not default constructor, just default arguments
    const Time t2{2};
    const Time t3{21, 34};
    const Time t4{12, 25, 42};

    std::cout << "Constructed with: \n\n";
    displayTime("t1: all arguments defaulted", t1);
    displayTime("t2: hour specified", t2);
    displayTime("t3: minute specified", t3);
    displayTime("t4: second specified", t4);

    try {
        const Time t5{27, 74, 99};
    }
    catch (const std::invalid_argument& e){
        std::cerr << fmt::format("t5 not created: {}\n", e.what());
    }
}