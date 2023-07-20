//
// Created by wbai on 7/20/2023.
//

#include "Employee.h"
#include <iostream>
#include <fmt/format.h>


Employee::Employee(std::string_view firstName, std::string_view lastName, const Date &birthDate, const Date &hireDate)
        : m_firstName{firstName}, m_lastName{lastName}, m_birthDate{birthDate}, m_hireDate{hireDate} {
    ++m_count;
    std::cout << fmt::format("Employee object constructor: {} {}\n", m_firstName, m_lastName);
}

std::string Employee::toString() const {
    return fmt::format("{}, {} Hired: {} Birthday: {}", m_lastName, m_firstName, m_hireDate.toString(),
                       m_birthDate.toString());
}

Employee::~Employee() {
    std::cout << fmt::format("Employee object destructor: {}, {}\n", m_lastName, m_firstName);
    --m_count;
}

int Employee::getCount() { return m_count; }

const std::string& Employee::getFirstName() const { return m_firstName; }

const std::string& Employee::getLastName() const { return m_lastName; }

