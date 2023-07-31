//
// Created by wbai on 7/31/2023.
//

#include "SalariedEmployeeNVI.h"
#include <fmt/format.h>
#include <stdexcept>


SalariedEmployeeNVI::SalariedEmployeeNVI(std::string_view name, double salary)
: EmployeeNVI{name} {
    setSalary(salary);
}

void SalariedEmployeeNVI::setSalary(double salary) {
    if (salary < 0.0) {
        throw std::invalid_argument("Weekly salary must be >= 0.0");
    }
    m_salary = salary;
}

double SalariedEmployeeNVI::getSalary() const { return m_salary; }

double SalariedEmployeeNVI::getPay() const { return getSalary(); }

std::string SalariedEmployeeNVI::getString() const {
    return fmt::format("{}\n{}: ${:.2f}", EmployeeNVI::getString(),
                       "salary", getSalary());
}