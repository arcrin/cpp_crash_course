//
// Created by wbai on 7/19/2023.
//

#ifndef CPP_CRASH_COURSE_DATE_H
#define CPP_CRASH_COURSE_DATE_H
#pragma once
#include <string>

class Date {
public:
    static const int monthsPerYear{12};

    Date(int year, int month, int day);

    std::string toString() const;

    ~Date();
private:
    int m_year;
    int m_month;
    int m_day;

    // utility function to check if day is proper for month and year
    bool checkDay(int day) const;
};


#endif //CPP_CRASH_COURSE_DATE_H
