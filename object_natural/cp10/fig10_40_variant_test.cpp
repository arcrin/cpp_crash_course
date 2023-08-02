//
// Created by wbai on 8/1/2023.
//
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include <vector>
#include "EmployeeVariant.h"
#include "SalariedVariant.h"
#include "CommissionedVariant.h"

int main() {
    EmployeeVariant salariedEmployee{"John Smith", SalariedVariant{800.0}};
    EmployeeVariant commissionedEmployee{"Sue Jones", CommissionedVariant{10000.0, 0.06}};

    std::vector employees{salariedEmployee, commissionedEmployee};

    for (const EmployeeVariant &employee: employees) {
        std::cout << fmt::format("{}\nearned: ${:.2f}\n\n", employee.toString(), employee.earnings());
    }
}