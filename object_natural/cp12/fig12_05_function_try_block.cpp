//
// Created by wbai on 8/9/2023.
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include <limits>
#include <stdexcept>

class Integer {
public:
    explicit Integer(int i) : value{i} {
        std::cout << fmt::format("Integer constructor: {}\n ", value)
                  << "Purposely throwing exception from Integer constructor\n";
        throw std::runtime_error("Integer constructor failed");
    }
    [[nodiscard]] int getValue() const { return value; }
    Integer() = default;
private:
    int value{};
};

class ResourceManager {
private:
    Integer myInteger;
public:
    explicit ResourceManager(int i) try : myInteger{i} {
        std::cout << "ResourceManager constructor called\n";
    }
    catch (const std::runtime_error& ex) {
        std::cout << fmt::format("Exception while constructing ResourceManager: ", ex.what())
                  << "\nAutomatically rethrowing the exception\n";
    }
};

int main() {
    try {
        const ResourceManager resource{7};
    }
    catch (const std::runtime_error &ex) {
        std::cout << fmt::format("Rethrown exception caught in main: {}\n", ex.what());
    }
}