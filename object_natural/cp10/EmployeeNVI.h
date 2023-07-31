//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_EMPLOYEENVI_H
#define CPP_CRASH_COURSE_EMPLOYEENVI_H
#define FMT_HEADER_ONLY
#pragma once
#include <string>
#include <string_view>

class EmployeeNVI {
public:
    explicit EmployeeNVI(std::string_view name);

    virtual ~EmployeeNVI() = default;

    void setName(std::string_view name);

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] double earnings() const;
    [[nodiscard]] std::string toString() const;
protected:
    [[nodiscard]] virtual std::string getString() const;
private:
    std::string m_name;

    [[nodiscard]] virtual double getPay() const = 0;
};


#endif //CPP_CRASH_COURSE_EMPLOYEENVI_H
