//
// Created by wbai on 7/31/2023.
//
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include <vector>
#include "EmployeeFinal.h"
#include "SalariedModel.h"
#include "CommissionModel.h"

int main() {
    SalariedModel salaried{800.0};
    EmployeeFinal salariedEmployee{"John Smith", &salaried};

    CommissionModel commission{10000, 0.06};
    EmployeeFinal commissionedEmployee{"Sue Jones", &commission};

    std::vector employees{salariedEmployee, commissionedEmployee};

    for (const EmployeeFinal &employee: employees) {
        std::cout << fmt::format("{}\nearned: ${:.2f}\n\n",
                                 employee.toString(), employee.earnings());
    }
}