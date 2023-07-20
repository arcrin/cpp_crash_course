//
// Created by wbai on 7/19/2023.
//
#include <fmt/format.h>
#include <iostream>
#include <string>
#include "Account.h"

int main() {
//    Account myAccount{"Empty"};

    // show that the initial value of myAccount's name is the empty string
//    std::cout << fmt::format("Initial account name: {}\n",
//                             myAccount.getName());

    // prompt for and read the name
//    std::cout << "Enter the account name: ";
//    std::string name{};
//    std::getline(std::cin, name);
//    myAccount.setName(name);

    // display the name stored in the object myAccount
//    std::cout << fmt::format("Updated account name: {}\n",
//                             myAccount.getName());

    // create two Account objects only with names, the default balance is 0.0
    Account account1{"Jane Green"};
    Account account2{"John Blue"};

    // display each Account's corresponding name
    std::cout << fmt::format(
            "account1 name is: {}\naccount2 name is: {}\n",
            account1.getName(), account2.getName()
    );

    // create two accounts with initialized balances
    Account account3{"Jane Green", 50.00};
    Account account4{"John Blue", -7.00};

    // display initial balance of each object
    std::cout << fmt::format("account3: {} balance is ${:.2f}\n",
                             account3.getName(), account3.getBalance());
    std::cout << fmt::format("account4: {} balance is ${:.2f}\n\n",
                             account4.getName(), account4.getBalance());

    std::cout << "Enter deposit amount for account3: ";
    double amount;
    std::cin >> amount;
    std::cout << fmt::format(
            "adding ${:.2f} to account3 balance\n\n", amount
    );
    account3.deposit(amount);

    // display balances
    std::cout << fmt::format("account3: {} balance is ${:.2f}\n",
                             account3.getName(), account3.getBalance());
    std::cout << fmt::format("account4: {} balance is ${:.2f}\n",
                             account4.getName(), account4.getBalance());
}