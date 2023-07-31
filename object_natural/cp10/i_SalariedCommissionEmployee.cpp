//
// Created by wbai on 7/26/2023.
//
#define FMT_HEADER_ONLY
#include "i_SalariedCommissionEmployee.h"
#include <fmt/format.h>
#include <stdexcept>

SalariedCommissionEmployee::SalariedCommissionEmployee(std::string_view name,
                                                       double salary,
                                                       double grossSales,
                                                       double commissionRate)
                                                       : i_SalariedEmployee{name, salary}, // base class initializer
                                                       m_grossSales{grossSales},
                                                         m_commissionRate{commissionRate}{
}

// set gross sales amount
void SalariedCommissionEmployee::setGrossSales(double grossSales) {
    if (grossSales < 0.0) {
        throw std::invalid_argument("Gross sales must be >= 0.0");
    }
    m_grossSales = grossSales;
}

// return gross sales amount
double SalariedCommissionEmployee::getGrossSales() const {
    return m_grossSales;
}

// return commission rate
void SalariedCommissionEmployee::setCommissionRate(double commissionRate) {
    m_commissionRate = commissionRate;
}

double SalariedCommissionEmployee::getCommissionRate() const {
    return m_commissionRate;
}

// calculate earnings--uses i_SalariedEmployee::earnings()
double SalariedCommissionEmployee::earnings() const {
    return i_SalariedEmployee::earnings() + getGrossSales() * getCommissionRate();
}

// returns string representation of SalariedCommissionEmployee object
std::string SalariedCommissionEmployee::toString() const {
    return fmt::format(
            "{}gross sales: ${:.2f}\ncommission rate: {:.2f}\n",
            i_SalariedEmployee::toString(), getGrossSales(), getCommissionRate()
    );
}