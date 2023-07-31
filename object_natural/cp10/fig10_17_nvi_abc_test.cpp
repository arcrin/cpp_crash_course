//
// Created by wbai on 7/31/2023.
//

#include <fmt/format.h>
#include <iostream>
#include <vector>
#include "EmployeeNVI.h"
#include "SalariedEmployeeNVI.h"
#include "CommissionEmployeeNVI.h"

void virtualViaPointer(const EmployeeNVI *baseClassPtr);

void virtualViaReference(const EmployeeNVI &baseClassRef);

int main() {
    SalariedEmployeeNVI salaried{"John Smith", 800.0};
    CommissionEmployeeNVI commission{"Sue Jones", 10000, 0.06};

    std::cout << "EmployeeNVIS PROCESSED INDIVIDUALLY VIA VARIABLE NAMES\n"
              << fmt::format("{}\n{}{:.2f}\n\n{}\n{}{:.2f}\n\n",
                             salaried.toString(), "earned $", salaried.earnings(),
                             commission.toString(), "earned $", commission.earnings());

    std::vector<EmployeeNVI *> EmployeeNVIs{&salaried, &commission};

    std::cout << "EmployeeNVIS PROCESSED POLYMORPHICALLY VIA"
              << " DYNAMIC BINDING\n\n";

    std::cout << "VIRTUAL FUNCTION CALLS MADE VIA BASE-CLASS POINTER";

    for (const EmployeeNVI* EmployeeNVIPtr : EmployeeNVIs) {
        virtualViaPointer(EmployeeNVIPtr);
    }

    std::cout << "VIRTUAL FUNCTION CALLS MADE VIA BASE-CLASS REFERENCES";

    for (const EmployeeNVI *EmployeeNVIPtr: EmployeeNVIs) {
        virtualViaReference(*EmployeeNVIPtr);
    }
}

// call EmployeeNVI virtual functions toString and earnings via a
// base-class pointer using dynamic binding
void virtualViaPointer(const EmployeeNVI *baseClassPtr) {
    std::cout << fmt::format("{}\nearned ${:.2f}\n\n",
                             baseClassPtr->toString(), baseClassPtr->earnings());
}

// call EmployeeNVI virtual functions toString and earnings via a
// base-class reference using dynamic binding
void virtualViaReference(const EmployeeNVI& baseClassRef) {
    std::cout << fmt::format("{}\nearned ${:.2f}\n\n",
                             baseClassRef.toString(), baseClassRef.earnings());
}