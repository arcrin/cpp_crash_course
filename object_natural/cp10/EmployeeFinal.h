//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_EMPLOYEEFINAL_H
#define CPP_CRASH_COURSE_EMPLOYEEFINAL_H
#pragma once
#include <string>
#include <string_view>
#include "CompensationModel.h"


class EmployeeFinal final {
public:
    EmployeeFinal(std::string_view name, CompensationModel *modelPtr);

    void setCompensationModel(CompensationModel *modelPtr);

    [[nodiscard]] double earnings() const;

    std::string toString() const;
private:
    std::string m_name{};
    CompensationModel *m_modelPtr{};
};


#endif //CPP_CRASH_COURSE_EMPLOYEEFINAL_H
