//
// Created by wbai on 7/25/2023.
//

#ifndef CPP_CRASH_COURSE_SALARIEDEMPLOYEE_H
#define CPP_CRASH_COURSE_SALARIEDEMPLOYEE_H
#pragma once
#include <string>
#include <string_view>

class SalariedEmployee {
public:
    SalariedEmployee(std::string_view name, double salary);

    void setName(std::string_view name);
    [[nodiscard]]std::string getName() const;

    void setSalary(double salary);
    [[nodiscard]]double getSalary() const;

    [[nodiscard]] virtual double earnings() const;
    [[nodiscard]] virtual std::string toString() const;

    virtual ~SalariedEmployee() = default;

private:
    std::string m_name{};
    double m_salary{0.0};
};


#endif //CPP_CRASH_COURSE_SALARIEDEMPLOYEE_H
