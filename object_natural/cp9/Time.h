//
// Created by wbai on 7/19/2023.
//

#ifndef CPP_CRASH_COURSE_TIME_H
#define CPP_CRASH_COURSE_TIME_H
#pragma once // prevent multiple inclusions of header
#include <string>

// Time class definition
class Time {
public:
    Time();

    explicit Time(int hour);

    Time(int hour, int minute);

    Time(int hour, int minute, int second);
//    explicit Time(int hour = 0, int minute = 0, int second = 0); // this is made explicit because it can be called with one parameter


    // set functions
    void setTime(int hour, int minute, int second);

    void setHour(int hour);

    void setMinute(int minute);

    void setSecond(int second);

    // get functions
    [[nodiscard]] int getHour() const;

    [[nodiscard]] int getMinute() const;

    [[nodiscard]] int getSecond() const;

    [[nodiscard]]std::string to24HourString() const; //const method, these member functions does not modify the state of the object
    [[nodiscard]]std::string to12HourString() const;
private:
    int m_hour{0};
    int m_minute{0};
    int m_second{0};
};


#endif //CPP_CRASH_COURSE_TIME_H
