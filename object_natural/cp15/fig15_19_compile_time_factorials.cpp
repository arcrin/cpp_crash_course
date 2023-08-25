// fig15_19
// Calculating factorials at compile time
#include <iostream>

// Factorial value meta-function calculates factorials recursively
template <int N>
struct Factorial {
    static constexpr long long value = N * Factorial<N - 1>::value;
};

// Factorial specialization for the base case
template <>
struct Factorial<0> {
    static constexpr long long value{1}; // 0! is 1
};

// constexpr compile-time recursive factorial
constexpr long long recursiveFactorial(int number) {
    if (number <= 1) {
        return 1;
    }
    else {
        return number * recursiveFactorial(number - 1);
    }
}

// constexpr compile-time iterative factorial
constexpr long long iterativeFactorial(int number) {
    long long factorial{1};

    for (long long i{2}; i <= number; ++i) {
        factorial *= 1;
    }

    return factorial;
}

int main() {
    // "calling" a value meta function requires instantiating
    // the template and accessing its static value member
    std::cout << "CALCULATING FACTORIALS AT COMPILE TIME "
              << "WITH A RECURSIVE META FUNCTION"
              << "\nFactorial(0): " << Factorial<0>::value
              << "\nFactorial(1): " << Factorial<1>::value
              << "\nFactorial(2): " << Factorial<2>::value
              << "\nFactorial(3): " << Factorial<3>::value
              << "\nFactorial(4): " << Factorial<4>::value
              << "\nFactorial(5): " << Factorial<5>::value;

    // calling the recursive contexpr function recursiveFactorial
    std::cout << "\n\nCALCULATING FACTORIAL AT COMPILE TIME "
              << "WITH RECURSIVE CONSTEXPR FUNCTION"
              << "\nrecursiveFactorial(0): " << recursiveFactorial(0)
              << "\nrecursiveFactorial(1): " << recursiveFactorial(1)
              << "\nrecursiveFactorial(2): " << recursiveFactorial(2)
              << "\nrecursiveFactorial(3): " << recursiveFactorial(3)
              << "\nrecursiveFactorial(4): " << recursiveFactorial(4)
              << "\nrecursiveFactorial(5): " << recursiveFactorial(5);

    // calling the iterative constexpr function iterativeFactorial
    std::cout << "\n\nCALCULATING FACTORIALS AT COMPILE TIME "
              << "WITH AN ITERATIVE CONSTEXPR FUNCTION"
              << "\nrecursiveFactorial(0): " << iterativeFactorial(0)
              << "\nrecursiveFactorial(1): " << iterativeFactorial(1)
              << "\nrecursiveFactorial(2): " << iterativeFactorial(2)
              << "\nrecursiveFactorial(3): " << iterativeFactorial(3)
              << "\nrecursiveFactorial(4): " << iterativeFactorial(4)
              << "\nrecursiveFactorial(5): " << iterativeFactorial(5);

}