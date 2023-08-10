//
// Created by wbai on 8/10/2023.
#define FMT_HEADER_ONLY
#include <array>
#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <new>

// handle memory allocation failure
void customNewHandler() {
    std::cerr << "customNewHandler was called\n";
    std::exit(EXIT_FAILURE);
}

int main() {
    std::array<std::unique_ptr<double[]>, 1000> items{};

    // specify that customNewHandler should be called on
    // memory allocation failure, this is a call back
    std::set_new_handler(customNewHandler);

    // aim each unique_ptr at a big block of memory
    for (int i{0}; auto& item : items) {
        item = std::make_unique<double[]>(500'000'000);
        std::cout << fmt::format(
                "items[{}] points to 500,000,000 doubles\n", i++);
    }
}