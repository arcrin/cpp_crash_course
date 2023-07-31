//
// Created by wbai on 7/31/2023.
//
#include "Employee.h"
#include <fmt/format.h>

Employee::Employee(std::string_view name) : m_name{name} {}

void Employee::setName(std::string_view name) { m_name = name; }

std::string Employee::getName() const { return m_name; }

std::string Employee::toString() const {
    return fmt::format("name: {}", getName());
}