//
// Created by wbai on 7/31/2023.
//

#include "CommissionEmployeeNVI.h"
#include <fmt/format.h>
#include <stdexcept>


CommissionEmployeeNVI::CommissionEmployeeNVI(std::string_view name, double grossSales, double commissionRate)
: EmployeeNVI{name} {
    setGrossSales(grossSales);
    setCommissionRate(commissionRate);
}

void CommissionEmployeeNVI::setGrossSales(double grossSales) {
    if (grossSales < 0.0) {
        throw std::invalid_argument("Gross sales must be >= 0.0");
    }
    m_grossSales = grossSales;
}

double CommissionEmployeeNVI::getGrossSales() const { return m_grossSales; }

void CommissionEmployeeNVI::setCommissionRate(double commissionRate) {
    if (commissionRate <= 0.0 || commissionRate >= 1.0) {
        throw std::invalid_argument(
                "Commission rate must be > 0.0 and < 1.0"
        );
    }
    m_commissionRate = commissionRate;
}

double CommissionEmployeeNVI::getCommissionRate() const {
    return m_commissionRate;
}

double CommissionEmployeeNVI::getPay() const {
    return getGrossSales() * getCommissionRate();
}

std::string CommissionEmployeeNVI::getString() const {
    return fmt::format(
            "{}\n{}: ${:.2}\n{}: {:.2f}", EmployeeNVI::getString(), "gross sales", getGrossSales(), "commission rate",
            getCommissionRate()
    );
}