//
// Created by wbai on 7/31/2023.
//

#ifndef CPP_CRASH_COURSE_COMMISSIONEMPLOYEENVI_H
#define CPP_CRASH_COURSE_COMMISSIONEMPLOYEENVI_H
#include <string>
#include <string_view>
#include "EmployeeNVI.h"

class CommissionEmployeeNVI final : public EmployeeNVI {
public:
    CommissionEmployeeNVI(std::string_view name, double grossSales, double commissionRate);

    virtual ~CommissionEmployeeNVI() = default;

    void setGrossSales(double grossSales);
    double getGrossSales() const;

    void setCommissionRate(double commissionRate);
    double getCommissionRate() const;
private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};

    // keyword override signals intent to override
    double getPay() const override;
    std::string getString() const override;
};


#endif //CPP_CRASH_COURSE_COMMISSIONEMPLOYEENVI_H
