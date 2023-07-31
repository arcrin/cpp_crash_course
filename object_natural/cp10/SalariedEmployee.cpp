//
// Created by wbai on 7/31/2023.
//

#include "SalariedEmployee.h"
#include <fmt/format.h>
#include <stdexcept>

SalariedEmployee::SalariedEmployee(std::string_view name, double salary) : Employee{name} {
    setSalary(salary);
}

void SalariedEmployee::setSalary(double salary) {
    if (salary < 0.0) {
        throw std::invalid_argument("Weekly salary must be >= 0.0");
    }
    m_salary = salary;
}

double SalariedEmployee::getSalary() const { return m_salary; }

double SalariedEmployee::earnings() const { return getSalary(); }

std::string SalariedEmployee::toString() const {
    return fmt::format("{}\n{}: ${:.2f}", Employee::toString(), "salary", getSalary());
}