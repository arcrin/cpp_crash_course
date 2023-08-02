//
// Created by wbai on 8/1/2023.
//

#ifndef CPP_CRASH_COURSE_MULTIDERIVED_H
#define CPP_CRASH_COURSE_MULTIDERIVED_H
#pragma once
#include <iostream>
#include <string>
#include "Base1.h"
#include "Base2.h"


class MultiDerived : public Base1, public Base2 {
public:
    MultiDerived(int value, char letter, double real);

    [[nodiscard]] double getReal() const;

    [[nodiscard]] std::string toString() const;
private:
    double m_real;
};


#endif //CPP_CRASH_COURSE_MULTIDERIVED_H
