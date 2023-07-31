//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_COMPENSATIONMODEL_H
#define CPP_CRASH_COURSE_COMPENSATIONMODEL_H
#pragma once
#include <string>


class CompensationModel {
public:
    virtual ~CompensationModel() = default;

    [[nodiscard]] virtual double earnings() const = 0;

    [[nodiscard]] virtual std::string toString() const = 0;
};


#endif //CPP_CRASH_COURSE_COMPENSATIONMODEL_H
