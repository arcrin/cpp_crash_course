//
// Created by wbai on 7/26/2023.
//

#ifndef CPP_CRASH_COURSE_SALARIEDCOMMISSIONEMPLOYEE_H
#define CPP_CRASH_COURSE_SALARIEDCOMMISSIONEMPLOYEE_H
#pragma once
#include <string>
#include <string_view>
#include "SalariedEmployee.h"


class SalariedCommissionEmployee : public SalariedEmployee {
public:
    SalariedCommissionEmployee(std::string_view name, double salary, double grossSales, double commissionRate);

    void setGrossSales(double grossSales);
    [[nodiscard]] double getGrossSales() const;

    void setCommissionRate(double commissionRate);
    [[nodiscard]] double getCommissionRate() const;

    [[nodiscard]] double earnings() const override;

    [[nodiscard]] std::string toString() const override;

private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};

};


#endif //CPP_CRASH_COURSE_SALARIEDCOMMISSIONEMPLOYEE_H
