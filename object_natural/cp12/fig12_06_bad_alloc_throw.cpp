//
// Created by wbai on 8/10/2023.
#define FMT_HEADER_ONLY
#include <array>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <new>

int main() {
    std::array<std::unique_ptr<double[]>, 1000> items{};

    // aim each unique_ptr at a big block of memory
    try {
        for (int i{0}; auto& item : items) {
            item = std::make_unique<double[]>(500'000'000);
            std::cout << fmt::format(
                    "items[{}] points to 500,000,000 doubles\n", i++);
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << fmt::format("Exception occurred: {}\n", e.what());
    }
}