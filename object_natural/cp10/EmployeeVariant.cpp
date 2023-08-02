//
// Created by wbai on 8/1/2023.
//

#include <fmt/format.h>
#include <string>
#include <variant>
#include "EmployeeVariant.h"

EmployeeVariant::EmployeeVariant(std::string_view name, CompensationModel model)
: m_name{name}, m_model{model} {}

void EmployeeVariant::setCompensationModel(CompensationModel model) {
    m_model = model;
}

double EmployeeVariant::earnings() const {
    auto getEarnings{[](const auto& model) { return model.earnings(); }};
    return std::visit(getEarnings, m_model); // apply m_model to getEarnings lambda
}

std::string EmployeeVariant::toString() const {
    auto getString{[](const auto& model) { return model.toString(); }};
    return fmt::format("{}\n{}", m_name, std::visit(getString, m_model));
}