//
// Created by wbai on 7/19/2023.
//

#ifndef CPP_CRASH_COURSE_DATE_H
#define CPP_CRASH_COURSE_DATE_H
#pragma once
#include <string>

class Date {
public:
    Date(int year, int month, int day);

    std::string toString() const;
private:
    int m_year;
    int m_month;
    int m_day;
};


#endif //CPP_CRASH_COURSE_DATE_H
