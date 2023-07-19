//
// Created by wbai on 7/18/2023.
//
#include <fmt/format.h>
#include <iostream>
#include "rapidcsv.h"
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path currentPath(__FILE__);
    fs::path parentPath = currentPath.parent_path();
    fs::path filePath = parentPath / "accounts.csv";
    std::cout << filePath.string();
    rapidcsv::Document document{filePath.string()}; // loads accounts.csv
    std::vector<int> accounts{document.GetColumn<int>("account")};
    std::vector<std::string> names{
            document.GetColumn<std::string>("name")
    };
    std::vector<double> balances{document.GetColumn<double>("balance")};

    std::cout << fmt::format(
            "{:<10}{:<13}{:>7}\n", "Account", "Name", "Balance"
    );
    for (size_t i{0}; i < accounts.size(); ++i) {
        std::cout << fmt::format("{:<10}{:<13}{:>7.2f}\n",
                                 accounts.at(i), names.at(i), balances.at(i));
    }
}