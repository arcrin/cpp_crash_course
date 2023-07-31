//
// Created by wbai on 7/27/2023.
//
#include "i_SalariedEmployee.h"
#include "i_SalariedCommissionEmployee.h"

int main() {
    SalariedEmployee salaried{"Sue Jones", 500.0};

    // assign derived-class pointer to base-class object
    // Error: a SalariedEmployee is not a SalariedCommissionEmployee
    SalariedCommissionEmployee *salariedCommissionPtr{&salaried};
}