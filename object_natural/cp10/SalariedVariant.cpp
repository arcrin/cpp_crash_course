//
// Created by wbai on 8/1/2023.
//

#include <fmt/format.h>
#include <stdexcept>
#include "SalariedVariant.h"

SalariedVariant::SalariedVariant(double salary) : m_salary{salary} {
    if (m_salary < 0.0) {
        throw std::invalid_argument("Weekly salary must be >= 0.0");
    }
}

double SalariedVariant::earnings() const { return m_salary; }

std::string SalariedVariant::toString() const {
    return fmt::format("salary: ${:.2f}", m_salary);
}