// fig15_15
// Unary fold expression
#include  <fmt/format.h>
#include <iostream>

template<typename... Items>
auto unaryLeftAdd(Items... items) {
    return (... + items); // unary left fold
}

template<typename... Items>
auto unaryRightAdd(Items... items) {
    return (items + ...);
}

template<typename... Items>
auto unaryLeftSubtract(Items... items) {
    return (... - items);
}

template<typename... Items>
auto unaryRightSubtract(Items... items) {
    return (items - ...);
}

int main() {
    std::cout << "Unary left and right fold with addition:"
              << fmt::format("\n{}{}\n{}{}\n\n",
                             "unaryLeftAdd(1, 2, 3, 4): ", unaryLeftAdd(1, 2, 3, 4),
                             "unaryRightAdd(1, 2, 3, 4)", unaryRightAdd(1, 2, 3, 4));

    std::cout << "Unary left and right subtract: "
              << fmt::format("\n{}{}\n{}{}\n\n",
                             "unaryLeftSubtract(1, 2, 3, 4): ", unaryLeftSubtract(1, 2, 3, 4),
                             "unaryRightSubtract(1, 2, 3, 4: ", unaryRightSubtract(1, 2, 3, 4));
}