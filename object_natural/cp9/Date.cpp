//
// Created by wbai on 7/19/2023.
//

#include "Date.h"
#include <fmt/format.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <array>

Date::Date(int year, int month, int day)
: m_year{year}, m_month{month}, m_day{day} {
    if (m_month < 1 || m_month > monthsPerYear) {
        throw std::invalid_argument{"month must be 1-12"};
    }

    if (!checkDay(day)) {
        throw std::invalid_argument{
                "Invalid day for current month and year"
        };
    }

    std::cout << fmt::format("Date object constructor: {}\n", toString());
}

std::string Date::toString() const {
    return fmt::format("{}-{:02d}-{:02d}", m_year, m_month, m_day);
}

Date::~Date() {
    std::cout << fmt::format("Date object destructor: {}\n", this->toString()); // class member functions have access to
    // an implicit `this` pointer to the object on which the member function is called
    // Unlike Python, in C++, you need to explicitly use the `this` pointer to access member variables and
    // methods. The `this` pointer is automatically passed to member functions, so you don't need to explicitly
    // provide it when calling a member function
}

bool Date::checkDay(int day) const {
    static const std::array daysPerMonth{
            0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    if (1 <= day && day <= daysPerMonth.at(m_month)) {
        return true;
    }

    // leap year check for Feb
    if (m_month == 2 && day == 29 && (m_year % 400 == 0 || (m_year % 4 == 0 && m_year % 100 != 0))) {
        return true;
    }
    return false;
}