//
// Created by wbai on 7/20/2023.
//
#include <fmt/format.h>
#include <iostream>
#include "Employee.h"


int main() {
    std::cout << fmt::format("Initial employee count: {}\n", Employee::getCount());

    // the following scope creates and destroys
    // Employee objects before main terminates
    {
        const Date birth{1987, 7, 24};
        const Date hire{2018, 3, 12};
        const Employee e1{"Susan", "Baker", birth, hire};
        const Employee e2{"Robert", "Jones", birth, hire};

        std::cout << fmt::format("Employee count after creating objects: {}\n\n", Employee::getCount());
        std::cout << fmt::format("Employee 1: {} {}\nEmployee 2: {} {}\n\n",
                                 e1.getFirstName(), e1.getLastName(),
                                 e2.getFirstName(), e2.getLastName()
        );
    }
    std::cout << fmt::format(
            "Employee count after objects are deleted: {}\n",
            Employee::getCount()
    );
}