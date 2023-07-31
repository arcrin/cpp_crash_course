//
// Created by wbai on 7/25/2023.
//
#include <fmt/format.h>
#include <stdexcept>
#include "i_SalariedEmployee.h"

i_SalariedEmployee::i_SalariedEmployee(std::string_view name, double salary)
: m_name{name}{
    setSalary(salary);
}

void i_SalariedEmployee::setName(std::string_view name) {
    m_name = name;
}

std::string i_SalariedEmployee::getName() const { return m_name; }

void i_SalariedEmployee::setSalary(double salary) {
    if (salary < 0.0) {
        throw std::invalid_argument("Salary must be >= 0.0");
    }

    m_salary = salary;
}

double i_SalariedEmployee::getSalary() const { return m_salary; }

double i_SalariedEmployee::earnings() const { return getSalary(); }

std::string i_SalariedEmployee::toString() const {
    return fmt::format("name: {}\nsalary: ${:.2f}\n", getName(), getSalary());
}