//
// Created by wbai on 7/25/2023.
//
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include "SalariedEmployee.h"

int main() {
    SalariedEmployee employee{"Sue Jones", 300.0};

    std::cout << "Employee information obtained by get functions:\n"
              << fmt::format("name: {}\nsalary: ${:.2f}\n", employee.getName(), employee.getSalary());
    employee.setSalary(500.0);
    std::cout << "\nUpdated employee information from function toString:\n"
              << employee.toString();
    std::cout << fmt::format("\nearnings: ${:.2f}\n", employee.earnings());
}