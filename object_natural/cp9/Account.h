//
// Created by wbai on 7/19/2023.
//

#ifndef CPP_CRASH_COURSE_ACCOUNT_H
#define CPP_CRASH_COURSE_ACCOUNT_H
#include <string>
#include <string_view>

class Account {
public:
    // constructor initializes data member m_name with the parameter name
    explicit Account(std::string_view name): m_name{name}, m_balance{0.0}{
        // member initializer
    }

    // Account constructor with two parameters
    Account(std::string_view name, double balance): m_name{name}, m_balance{std::max(0.0, balance)} {

    }

    // keep the default constructor
    Account() = default;

    // function that deposits (adds) only a valid amount to the balance
    void deposit(double amount) {
        if (amount > 0.0) {
            m_balance += amount;
        }
    }

    // function that returns the account balance
    [[nodiscard]] double getBalance() const {
        return m_balance;
    }


    // member function that sets m_name in the object
    void setName(std::string_view name) {
        m_name = name;
    }

    // member function that retrieves the account name from the object
    [[nodiscard]] const std::string& getName() const {
        return m_name;
    }
private:
    std::string m_name;
    double m_balance;
};

#endif //CPP_CRASH_COURSE_ACCOUNT_H
