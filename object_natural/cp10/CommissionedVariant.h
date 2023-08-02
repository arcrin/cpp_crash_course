//
// Created by wbai on 8/1/2023.
//

#ifndef CPP_CRASH_COURSE_COMMISSIONEDVARIANT_H
#define CPP_CRASH_COURSE_COMMISSIONEDVARIANT_H
#pragma once
#include <string>

class CommissionedVariant {
public:
    CommissionedVariant(double grossSales, double commissionRate);
    double earnings() const;
    std::string toString() const;
private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};
};


#endif //CPP_CRASH_COURSE_COMMISSIONEDVARIANT_H
