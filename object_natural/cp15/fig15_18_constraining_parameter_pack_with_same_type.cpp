// fig15_18
// Constraining a variadic-function-template parameter pack to
// elements of the same type
#include <concepts>
#include <iostream>
#include <string>

template<typename T, typename... Us>
concept SameTypeElements = (std::same_as<T, Us> && ...);

// add one or more arguments with a fold expression
template<typename FirstItem, typename... RemainingItems>
requires SameTypeElements<FirstItem, RemainingItems...>
auto foldingSum(FirstItem first, RemainingItems... theRest) {
    return (first + ... + theRest);
}

int main() {
    using namespace std::literals;

    foldingSum(1, 2, 3);
    foldingSum("s"s, "u"s, "m"s);
    foldingSum(1, 2.2, "hello"s);
}


