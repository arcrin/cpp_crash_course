//
// Created by wbai on 8/1/2023.
//

#ifndef CPP_CRASH_COURSE_SALARIEDVARIANT_H
#define CPP_CRASH_COURSE_SALARIEDVARIANT_H
#pragma once
#include <string>

class SalariedVariant {
public:
    SalariedVariant(double salary);

    double earnings() const;

    std::string toString() const;
private:
    double m_salary{0.0};
};


#endif //CPP_CRASH_COURSE_SALARIEDVARIANT_H
