//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_COMMISSIONMODEL_H
#define CPP_CRASH_COURSE_COMMISSIONMODEL_H
#pragma once
#include <string>
#include "CompensationModel.h"

class CommissionModel final : public CompensationModel {
public:
    CommissionModel(double grossSales, double commissionRate);

    [[nodiscard]] double earnings() const override;

    [[nodiscard]] std::string toString() const override;
private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};
};


#endif //CPP_CRASH_COURSE_COMMISSIONMODEL_H
