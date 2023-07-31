//
// Created by wbai on 7/26/2023.
//
//#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include "i_SalariedCommissionEmployee.h"

int main() {
    // instantiate SalariedCommissionEmployee object
    SalariedCommissionEmployee employee{"Bob Lewis", 300.0, 5000.0, 0.04};

    // get SalariedCommissionEmployee data
    std::cout << "Employee information obtained by get functions:\n"
              << fmt::format("{}: {}\n{}: {:.2f}\n{}: {:.2f}\n{}: {:.2f}\n",
                             "name", employee.getName(), "salary", employee.getSalary(),
                             "gross sales", employee.getGrossSales(),
                             "commission", employee.getCommissionRate());

    employee.setGrossSales(8000.0);
    employee.setCommissionRate(0.1);
    std::cout << "\nUpdated employee information from function toString:\n"
              << employee.toString();

    // display the employee's earnings
    std::cout << fmt::format("\nearnings: ${:.2f}\n", employee.earnings());
}