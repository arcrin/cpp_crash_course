//
// Created by wbai on 7/20/2023.
//

#ifndef CPP_CRASH_COURSE_EMPLOYEE_H
#define CPP_CRASH_COURSE_EMPLOYEE_H
#pragma once
#include <string>
#include <string_view>
#include "Date.h"

class Employee {
public:
    Employee(std::string_view firstName, std::string_view lastName, const Date &birthDate, const Date &hireDate);

    [[nodiscard]] std::string toString() const;

    ~Employee(); // provided to confirm destruction order

    const std::string& getFirstName() const;

    const std::string& getLastName() const;

    static int getCount();
private:
    std::string m_firstName;
    std::string m_lastName;
    Date m_birthDate;
    Date m_hireDate;

    inline static int m_count{0};
};


#endif //CPP_CRASH_COURSE_EMPLOYEE_H
