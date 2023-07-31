//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_SALARIEDEMPLOYEENVI_H
#define CPP_CRASH_COURSE_SALARIEDEMPLOYEENVI_H
#pragma once
#include <string>
#include <string_view>
#include "EmployeeNVI.h"


class SalariedEmployeeNVI final : public EmployeeNVI{
public:
    SalariedEmployeeNVI(std::string_view name, double salary);

    virtual ~SalariedEmployeeNVI() = default;

    void setSalary(double salary);
    double getSalary() const;
private:
    double m_salary{0.0};

    // keyword override signals intent to override
    double getPay() const override;

    std::string getString() const override;
};


#endif //CPP_CRASH_COURSE_SALARIEDEMPLOYEENVI_H
