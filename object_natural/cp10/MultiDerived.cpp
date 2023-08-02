//
// Created by wbai on 8/1/2023.
//

#include <fmt/format.h>
#include "MultiDerived.h"


MultiDerived::MultiDerived(int value, char letter, double real) : Base1{value}, Base2{letter}, m_real{real} {}

double MultiDerived::getReal() const { return m_real; }

std::string MultiDerived::toString() const {
    // use scope resolution operator to specify the function I want to access
    return fmt::format("int: {}; char: {}; double: {}", Base1::getData(), Base2::getData(), getReal());
}