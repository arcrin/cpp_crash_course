//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_SALARIEDEMPLOYEE_H
#define CPP_CRASH_COURSE_SALARIEDEMPLOYEE_H
#pragma once
#include <string>
#include <string_view>
#include "Employee.h" // Employee class definition

class SalariedEmployee final : public Employee {
public:
    SalariedEmployee(std::string_view name, double salary);

    virtual ~SalariedEmployee() = default; // virtual destructor

    void setSalary(double salary);
    [[nodiscard]] double getSalary() const;

    [[nodiscard]] double earnings() const override; // override virtual function
    [[nodiscard]] std::string toString() const override;
private:
    double m_salary{0.0};
};

#endif //CPP_CRASH_COURSE_SALARIEDEMPLOYEE_H
