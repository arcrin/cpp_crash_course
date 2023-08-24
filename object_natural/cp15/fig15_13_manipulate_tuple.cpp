// fig15_13
// Manipulate tuples. tuple class is a variadic-class-template generalization of class template pair
#include <fmt/format.h>
#include <iostream>
#include <string>
#include <tuple>

// type alias for a tuple representing a hardware part's inventory
using Part = std::tuple<int, std::string, int, double>;

// return a part's inventory tuple
Part getInventory(int partNumber) {
    using namespace std::string_literals;

    switch (partNumber) {
        case 1:
            return {1, "Hammer"s, 32, 9.95};
        case 2:
            return {2, "Screwdriver"s, 106, 6.99};
        default:
            return {0, "INVALID PART", 0, 0.0};
    }
}

int main() {
    // display the hardware part inventory
    for (int i{1}; i <= 2; ++i) {
        // unpack the returned tuple into four variables;
        // variables' types are inferred from the tuple's element values
        auto [partNumber, partName, quantity, price] {getInventory(i)};
        std::cout << fmt::format("{}: {}, {}: {}, {}: {}, {}: {:.2f}\n",
                                 "Part number", partNumber, "Tool", partName,
                                 "Quantity", quantity, "Price", price);
    }
    std::cout << "\nAccessing ga tuple's elements by index number: \n";
    auto hammer{getInventory(1)};
    std::cout << fmt::format("{}: {}, {}: {}, {}: {}, {}: {:.2f}\n",
                             "Part number", std::get<0>(hammer), "Tool", std::get<1>(hammer),
                             "Quantity", std::get<2>(hammer), "Price", std::get<3>(hammer));

    std::cout << fmt::format("A Part tuple has {} elements\n",
                             std::tuple_size<Part>{});
}