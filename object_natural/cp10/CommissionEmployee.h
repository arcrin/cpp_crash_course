//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_COMMISIONEMPLOYEE_H
#define CPP_CRASH_COURSE_COMMISIONEMPLOYEE_H

#pragma once
#include <string>
#include <string_view>
#include "Employee.h"


class CommissionEmployee final : public  Employee{
public:
    CommissionEmployee(std::string_view name, double grossSales, double commissionRate);

    virtual ~CommissionEmployee() = default;

    void setGrossSales(double grossSales);
    double getGrossSales() const;

    void setCommissionRate(double commissionRate);
    double getCommissionRate() const;

    double earnings() const override;
    std::string toString() const override;
private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};
};


#endif //CPP_CRASH_COURSE_COMMISIONEMPLOYEE_H
