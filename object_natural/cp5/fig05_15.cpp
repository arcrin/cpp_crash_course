//
// Created by wbai on 4/6/2023.
// recursive function factorial
//
#include <iostream>
#include <iomanip>

using namespace std;

long factorial(int number); // function prototype

int main() {
    // calculate the factorials of 0 through 10
    for (int counter{0}; counter <= 10; ++counter) {
        cout << setw(2) << counter << "! = " << factorial(counter)
             << '\n';
    }
}

// recursive definition of function factorial
long factorial(int number) {
    if (number <= 1) {
        return 1;
    }
    else {
        return number * factorial(number - 1);
     }
}
