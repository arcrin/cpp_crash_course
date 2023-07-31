//
// Created by wbai on 7/27/2023.
//
#include <string>
#include "i_SalariedEmployee.h"
#include "i_SalariedCommissionEmployee.h"

int main() {
    SalariedCommissionEmployee salariedCommission{
            "Bob Lewis", 300.0, 5000.0, 0.04
    };

    // assign base-class pointer at derived-class object (allowed)
    SalariedEmployee *salariedPtr{&salariedCommission};

    // invoke base-class member functions on derived-class
    // object through base-class pointer (allowed)
    std::string name{salariedPtr->getName()};
    double salary{salariedPtr->getSalary()};

    // attempt to invoke derived-class-only member functions
    // on derived-class object through base-class pointer (disallowed)
    double grossSales{salariedPtr->getGrossSales()};
    double commissionRate{salariedPtr->getCommissionRate()};
    salariedPtr->setGrossSales(8000.0);
}