//
// Created by wbai on 8/1/2023.
//

#ifndef CPP_CRASH_COURSE_EMPLOYEEVARIANT_H
#define CPP_CRASH_COURSE_EMPLOYEEVARIANT_H
#pragma once
#include <string>
#include <string_view>
#include <variant>
#include "CommissionedVariant.h"
#include "SalariedVariant.h"

using CompensationModel = std::variant<CommissionedVariant, SalariedVariant>;

class EmployeeVariant {
public:
    EmployeeVariant(std::string_view name, CompensationModel model);

    void setCompensationModel(CompensationModel model);
    double earnings() const;
    std::string toString() const;
private:
    std::string m_name{};
    CompensationModel m_model;
};


#endif //CPP_CRASH_COURSE_EMPLOYEEVARIANT_H
