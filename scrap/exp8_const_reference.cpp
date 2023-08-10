//
// Created by wbai on 8/9/2023.
//
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>


class CustomClass {
public:
    explicit CustomClass(int value): m_value{value}{}
    [[nodiscard]]const int& getValue() const { return m_value; }
    CustomClass& getInstance() { return *this; }
    void setValue(int value) { m_value = value; }
private:
    int m_value;
};

int main() {
    CustomClass cc{1};
    std::cout << fmt::format("Initial value: {}\n", cc.getValue());
    cc.setValue(2);

    CustomClass &cc_instance = cc.getInstance();

    CustomClass cc99{99};
    cc_instance = cc99;
    std::cout << cc99.getValue();
}