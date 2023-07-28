//
// Created by wbai on 7/27/2023.
//
#include <fmt/format.h>
#include <iostream>
#include "SalariedEmployee.h"
#include "SalariedCommissionEmployee.h"

int main() {
    // create base-class object
    SalariedEmployee salaried{"Sue Jones", 500.0};

    // create derived-class object
    SalariedCommissionEmployee salariedCommission{
            "Bob Lewis", 300.0, 5000.0, 0.04
    };

    // output objects using static binding
    std::cout << fmt::format(
            "{}\n{}:\n{}\n{}\n",
            "Invoking toString function on base-class and",
            "derived-class objects with static binding",
            salaried.toString(),
            salariedCommission.toString()
    );
    std::cout << "Invoking toString function on base-class and\n"
              << "derived-class objects with dynamic binding\n\n";

    // assign base-class pointer at base-class object
    SalariedEmployee *salariedPtr{&salaried};
    std::cout << fmt::format("{}\n{}:\n{}\n",
            "CALLING VIRTUAL FUNCTION TOSTRING WITH BASE-CLASS POINTER",
            "TO BASE-CLASS OBJECT INVOKES BASE-CLASS FUNCTIONALITY",
            salariedPtr->toString()); // base-class version

    // derived-class to derived-class
    SalariedCommissionEmployee *salariedCommissionPtr{&salariedCommission};
    std::cout << fmt::format("{}\n{}:\n{}\n",
            "CALLING VIRTUAL FUNCTION TOSTRING WITH DERIVED-CLASS POINTER",
            "TO DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS FUNCTIONALITY",
            salariedCommissionPtr->toString()); // derived-class version

    // base-class to derived-class
    salariedPtr = &salariedCommission;

    // runtime polymorphism: invokes SalariedCommission Employee
    // via base-class pointer to derived-class object
    std::cout << fmt::format("{}\n{}:\n{}\n",
                "CALLING VIRTUAL FUNCTION TOSTRING WITH BASE-CLASS POINTER",
                "TO DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS FUNCTIONALITY",
                salariedPtr->toString()); // derived-class version

}