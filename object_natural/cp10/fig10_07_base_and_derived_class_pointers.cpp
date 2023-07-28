//
// Created by wbai on 7/27/2023.
//
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include "SalariedEmployee.h"
#include "SalariedCommissionEmployee.h"

int main() {
    // create base-class object
    SalariedEmployee salaried{"Sue Jones", 500.0};

    // create derived-class object
    SalariedCommissionEmployee salariedCommission{
            "Bob Lewis", 300.0, 5000.0, .04
    };

    std::cout << fmt::format("{}:\n{}\n{}\n",
            "DISPLAY BASE-CLASS AND DERIVED-CLASS OBJECTS",
            salaried.toString(), // base-class toString
            salariedCommission.toString()); // derived-class toString

    // assign base-class pointer to a base-class object
    SalariedEmployee *salariedPtr{&salaried};
    std::cout << fmt::format("{}\n{}:\n{}\n",
                             "Calling toString with base-class pointer to ",
                             "base-class object invokes base-class functionality",
                             salariedPtr->toString());

    // assign derived-class pointer to derived-class object
    SalariedCommissionEmployee *salariedCommissionPtr{&salariedCommission};
    std::cout << fmt::format("{}\n{}:\n{}\n",
                             "Calling toString with derived-class pointer to",
                             "derived-class object invokes derived-class functions",
                             salariedCommissionPtr->toString());

    // assign base-class pointer to derived-class object
    salariedPtr = &salariedCommission;
    std::cout << fmt::format("{}\n{}:\n{}\n",
        "CALLING TOSTRING WITH BASE-CLASS POINTER TO DERIVED-CLASS",
        "OBJECT INVOKES BASE-CLASS FUNCTIONALITY",
        salariedPtr->toString()); // baseclass version
}