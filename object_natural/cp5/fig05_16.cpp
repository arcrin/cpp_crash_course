//
// Created by wbai on 4/6/2023.
// recursive fibonacci
//
#include <iostream>
using namespace std;

long fibonacci(long number);

int main() {
    for (int counter{0}; counter <= 10; ++counter) {
        cout << "fibonacci(" << counter << ") = "
             << fibonacci(counter) << '\n';
    }
    cout << "fibonacci(20)" << fibonacci(20) << '\n';
    cout << "fibonacci(30)" << fibonacci(30) << '\n';
    cout << "fibonacci(35)" << fibonacci(35) << '\n';
}

long fibonacci(long number) {
    if ((number == 0) || (number == 1)) {
        return 1;
    } else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}