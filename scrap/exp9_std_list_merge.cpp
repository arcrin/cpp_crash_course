//
// Created by wbai on 8/10/2023.
//
#define FMT_HEADER_ONLY
#include <list>
#include <iostream>
#include <fmt/format.h>

int main() {
    std::list<int> values1{1, 3, 5};
    std::list<int> values2{2, 4, 6};

    values1.merge(values2);
    for (auto &value: values1) {
        std::cout << value << ' ';
    }
}