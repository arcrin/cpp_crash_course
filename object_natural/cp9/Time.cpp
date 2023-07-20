//
// Created by wbai on 7/19/2023.
//
#include <fmt/format.h>
#include <stdexcept>
#include <string>
#include "Time.h"


//Time::Time() : Time{0, 0, 0} {}
//
//Time::Time(int hour) : Time{hour, 0, 0} {}
//
//Time::Time(int hour, int minute) : Time{hour, minute, 0} {}
//
// Time constructor initializes each data member
Time::Time(int hour, int minute, int second) {
    setTime(hour, minute, second);
}

Time& Time::setTime(int hour, int minute, int second) {
    if (hour < 0 || hour >= 24) {
        throw std::invalid_argument{"hour was out of range"};
    }

    if (minute < 0 || minute >= 60) {
        throw std::invalid_argument{"Minute was out of range"};
    }

    if (second < 0 || second >= 60) {
        throw std::invalid_argument{"second was out of range"};
    }

    m_hour = hour;
    m_minute = minute;
    m_second = second;
    return *this;
}

// set functions
Time& Time::setHour(int hour) { return setTime(hour, m_minute, m_second); }

Time& Time::setMinute(int minute) { return setTime(m_hour, minute, m_second); }

Time& Time::setSecond(int second) { return setTime(m_hour, m_minute, second); }

// get functions
int Time::getHour() const { return m_hour; }

int Time::getMinute() const { return m_minute; }

int Time::getSecond() const { return m_second; }

std::string Time::to24HourString() const {
    return fmt::format("{:02d}:{:02d}:{:02d}", m_hour, m_minute, m_second);
}

std::string Time::to12HourString() const {
    return fmt::format("{}:{:02d}:{:02d} {}",
                       getHour() % 12 == 0 ? 12 : getHour() % 12,
                       getMinute(),
                       getSecond(),
                       getHour() > 12 ? "PM" : "AM");
}