//
// Created by wbai on 4/4/2023.
//
// fig03_05.cpp
// integer ranges and arbitrary-precision integers
#include <iostream>
#include "bignumber.h"
#include <limits>
#include <cstdint>
using namespace std;

int main() {
    // use the maximum long long fundamental type value in calculations
//    const long long value1{9'223'372'036'854'775'807LL};
    const long long value1{numeric_limits<long long>::max()}; // long long max
    cout << "long long value1: " << value1
    << "\nvalue1 - 1: " << value1 - 1
    << "\nvalue1 + 1: " << value1 + 1; // result is undefined

    // use an arbitrary-precision integer
    const BigNumber value2{value1};
    cout << "\n\nBigNumber value2: " << value2
         << "\nvalue2 - 1: " << value2 - 1
         << "\nvalue2 + 1: " << value2 + 1;

    // powers of 100,000,000 with long long
    long long value3{100'000'000};
    cout << "\n\nvalue3: " << value3;
    std::uint16_t counter{2};

    while (counter <= 5) {
        value3 *= 100'000'000;
        cout << "\nvalue3 to the power " << counter << ": " << value3;
        ++counter;
    }

    // powers of 100,000,000 with BigNumber
    BigNumber value4{100'000'000};
    cout << "\n\nvalue4: " << value4 << "\n";

    counter = 2;

    while (counter <= 5) {
        cout << "value4.pow(" << counter << "): "
             << value4.pow(counter) << "\n";
        ++counter;
    }
    cout << "\n";
}