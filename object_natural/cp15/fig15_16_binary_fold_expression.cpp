// fig15_16
// Binary fold expressions
#include <fmt/format.h>
#include <iostream>

template<typename... Items>
auto binaryLeftAdd(Items... items) {
    return (0 + ... + items);
}

template<typename... Items>
auto binaryRightAdd(Items... items) {
    return (items + ... + 0);
}

template<typename... Items>
auto binaryLeftSubtract(Items... items) {
    return (0 - ... - items);
}

template<typename... Items>
auto binaryRightSubtract(Items... items) {
    return (items - ... - 0);
}


int main() {
      std::cout << "Binary left and right fold with addition:"
         << fmt::format("\n{}{}\n{}{}\n{}{}\n{}{}\n\n",
                     "binaryLeftAdd(): ", binaryLeftAdd(), // support empty pack
                     "binaryLeftAdd(1, 2, 3, 4): ", binaryLeftAdd(1, 2, 3, 4),
                     "binaryRightAdd(): ", binaryRightAdd(),
                     "binaryRightAdd(1, 2, 3, 4): ", binaryRightAdd(1, 2, 3, 4));

      std::cout << "Binary left and right fold with subtraction:"
         << fmt::format("\n{}{}\n{}{}\n{}{}\n{}{}\n",
                      "binaryLeftSubtract(): ", binaryLeftSubtract(),
                      "binaryLeftSubtract(1, 2, 3, 4): ",
                      binaryLeftSubtract(1, 2, 3, 4),
                      "binaryRightSubtract(): ", binaryRightSubtract(),
                      "binaryRightSubtract(1, 2, 3, 4): ",
                      binaryRightSubtract(1, 2, 3, 4));
}