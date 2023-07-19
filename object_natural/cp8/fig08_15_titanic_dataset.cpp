//
// Created by wbai on 7/18/2023.
//
#include <fmt/format.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <ranges>
#include "rapidcsv.h"
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path currentPath{__FILE__};
    fs::path parentPath = currentPath.parent_path();
    fs::path filePath = parentPath / "titanic.csv";
    // load Titanic dataset; treat missing age values as NaN
    rapidcsv::Document titanic{filePath.string(), rapidcsv::LabelParams{}, rapidcsv::SeparatorParams{},
                               rapidcsv::ConverterParams{true}};
    // GetColumn returns column's data as a vector of the appropriate type
    auto survived{titanic.GetColumn<int>("survived")};
    auto sex{titanic.GetColumn<std::string>("sex")};
    auto age{titanic.GetColumn<double>("age")};
    auto pclass{titanic.GetColumn<int>("pclass")};

    // display first 5 rows
    std::cout << fmt::format("First five rows:\n{:<10}{:<8}{:<6}{}\n", "survived", "gender", "age", "class");
    for (size_t i{0}; i < 5; ++i) {
        std::cout << fmt::format("{:<10}{:<8}{:6.1f}{}\n", survived.at(i), sex.at(i), age.at(i), pclass.at(i));
    }

    // display last 5 rows
    std::cout << fmt::format("First five rows:\n{:<10}{:<8}{:<6}{}\n", "survived", "gender", "age", "class");
    const auto count{titanic.GetRowCount()};
    for (size_t i{count - 5}; i < count; ++i) {
        std::cout << fmt::format("{:<10}{:<8}{:6.1f}{}\n", survived.at(i), sex.at(i), age.at(i), pclass.at(i));
    }

    // use C++20 ranges to eliminate missing values from age column
    auto removeNaN{
            age | std::views::filter([](const auto &x) { return !std::isnan(x); })
    };
    std::vector<double> cleanAge{
            std::begin(removeNaN), std::end(removeNaN)
    };

    // descriptive statistics for cleaned ages column
    std::sort(std::begin(cleanAge), std::end(cleanAge));
    size_t size{cleanAge.size()};
    double median{};


}