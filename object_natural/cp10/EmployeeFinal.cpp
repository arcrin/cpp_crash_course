//
// Created by wbai on 7/31/2023.
//

#include <fmt/format.h>
#include <string>
#include "EmployeeFinal.h"
#include "CompensationModel.h"

EmployeeFinal::EmployeeFinal(std::string_view name, CompensationModel *modelPtr)
: m_name{name}, m_modelPtr{modelPtr} {}

void EmployeeFinal::setCompensationModel(CompensationModel* modelPtr) {
    m_modelPtr = modelPtr;
}

double EmployeeFinal::earnings() const {
    return m_modelPtr->earnings();
}

std::string EmployeeFinal::toString() const {
    return fmt::format("{}\n{}", m_name, m_modelPtr->toString());
}