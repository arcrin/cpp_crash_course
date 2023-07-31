//
// Created by wbai on 7/31/2023.
//

#include "EmployeeNVI.h"
#include <fmt/format.h>

EmployeeNVI::EmployeeNVI(std::string_view name) : m_name{name} {}

void EmployeeNVI::setName(std::string_view name) { m_name = name; }

std::string EmployeeNVI::getName() const { return m_name; }

double EmployeeNVI::earnings() const { return getPay(); }

std::string EmployeeNVI::toString() const { return getString(); }

std::string EmployeeNVI::getString() const {
    return fmt::format("name: {}", getName());
}