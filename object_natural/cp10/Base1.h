//
// Created by wbai on 8/1/2023.
//

#ifndef CPP_CRASH_COURSE_BASE1_H
#define CPP_CRASH_COURSE_BASE1_H
#pragma once

class Base1{
public:
    explicit Base1(int value) : m_value{value} {}
    [[nodiscard]] int getData() const { return m_value; }
private:
    int m_value;
};

#endif //CPP_CRASH_COURSE_BASE1_H
