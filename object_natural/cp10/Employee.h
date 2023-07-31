//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_EMPLOYEE_H
#define CPP_CRASH_COURSE_EMPLOYEE_H
#define FMT_HEADER_ONLY
#pragma once
#include <string>
#include <string_view>

class Employee {
public:
    explicit Employee(std::string_view name);

    virtual ~Employee() = default; // compiler generate virtual destructor

    void setName(std::string_view name);

    [[nodiscard]] std::string getName() const;

    // pure virtual function makes Employee an abstract base class
    [[nodiscard]] virtual double earnings() const = 0; // pure virtual, makes the class a abc
    [[nodiscard]] virtual std::string toString() const; // virtual
private:
    std::string m_name;
};


#endif //CPP_CRASH_COURSE_EMPLOYEE_H
