//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_SALARIEDMODEL_H
#define CPP_CRASH_COURSE_SALARIEDMODEL_H
#pragma once
#include <string>
#include "CompensationModel.h"


class SalariedModel final : public CompensationModel {
public:
    explicit SalariedModel(double salary);

    double earnings() const override;

    std::string toString() const override;
private:
    double m_salary{0.0};
};


#endif //CPP_CRASH_COURSE_SALARIEDMODEL_H
