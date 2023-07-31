//
// Created by wbai on 7/31/2023.
//

#include <fmt/format.h>
#include <iostream>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"

void virtualViaPointer(const Employee *baseClassPtr);

void virtualViaReference(const Employee &baseClassRef);

int main() {
    SalariedEmployee salaried{"John Smith", 800.0};
    CommissionEmployee commission{"Sue Jones", 10000, 0.06};

    std::cout << "EMPLOYEES PROCESSED INDIVIDUALLY VIA VARIABLE NAMES\n"
              << fmt::format("{}\n{}{:.2f}\n\n{}\n{}{:.2f}\n\n",
                             salaried.toString(), "earned $", salaried.earnings(),
                             commission.toString(), "earned $", commission.earnings());

    std::vector<Employee *> employees{&salaried, &commission};

    std::cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA"
              << " DYNAMIC BINDING\n\n";

    std::cout << "VIRTUAL FUNCTION CALLS MADE VIA BASE-CLASS POINTER";

    for (const Employee* employeePtr : employees) {
        virtualViaPointer(employeePtr);
    }

    std::cout << "VIRTUAL FUNCTION CALLS MADE VIA BASE-CLASS REFERENCES";

    for (const Employee *employeePtr: employees) {
        virtualViaReference(*employeePtr);
    }
}

// call Employee virtual functions toString and earnings via a
// base-class pointer using dynamic binding
void virtualViaPointer(const Employee *baseClassPtr) {
    std::cout << fmt::format("{}\nearned ${:.2f}\n\n",
                             baseClassPtr->toString(), baseClassPtr->earnings());
}

// call Employee virtual functions toString and earnings via a
// base-class reference using dynamic binding
void virtualViaReference(const Employee& baseClassRef) {
    std::cout << fmt::format("{}\nearned ${:.2f}\n\n",
                             baseClassRef.toString(), baseClassRef.earnings());
}