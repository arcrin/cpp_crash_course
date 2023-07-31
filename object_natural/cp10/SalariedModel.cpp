//
// Created by wbai on 7/31/2023.
//

#include "SalariedModel.h"
#include <fmt/format.h>
#include <stdexcept>


SalariedModel::SalariedModel(double salary)
: m_salary{salary} {
    if (m_salary < 0.0) {
        throw std::invalid_argument("Weekly salary must be >= 0.0");
    }
}

double SalariedModel::earnings() const { return m_salary; }

std::string SalariedModel::toString() const {
    return fmt::format("salary: ${:.2f}", m_salary);
}