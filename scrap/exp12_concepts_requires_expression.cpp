//
// Created by wbai on 8/16/2023.
//
#include <ranges>
#include <iostream>
#include <array>
#include <vector>

// simple requirements
template<class T>
concept range = requires(T& t) {
    std::ranges::begin(t);
    std::ranges::end(t);
};

template<class T>
concept ArithmeticType = requires(T a, T b) {
    a + b;
    a - b;
    a * b;
    a / b;
    a += b;
    a -= b;
    a *= b;
    a /= b;
};

// type requirement
class SampleClass {
public:
    class NestedType {

    };
    void printMessage() { std::cout << "SampleClass with NestedType"; }
};

template<typename T>
concept HasValueType = requires {
    typename T::NestedType;
};

template <range range>
auto printRange(range& r) {
    auto iterBegin = std::ranges::begin(r);
    auto iterEnd = std::ranges::end(r);

    for (auto it = iterBegin; it != iterEnd; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

template<ArithmeticType A>
auto calculateSum(A first, A second) {
    return first + second;
}

template<HasValueType T>
auto evaluateCustomType(T &t) {
    t.printMessage();
}

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5};
    SampleClass sc{};

    printRange(numbers);

    std::cout << calculateSum(1, 2) << "\n";

    evaluateCustomType(sc);
}