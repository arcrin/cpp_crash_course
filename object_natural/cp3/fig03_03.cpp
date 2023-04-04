//
// Created by wbai on 4/4/2023.
// nested control statements
//

#include <iostream>
using namespace std;

int main() {
    int passes{0};
    int failures{0};
    int studentCounter{1}; // preventing narrowing conversions with braced initialization

    while (studentCounter <= 10) {
        cout << "Enter result (1 = pass, 2 = fail): ";
        int result;
        cin >> result;

        // if...else is nested in the while statement
        if (result == 1) {
            passes += 1;
        } else {
            failures += 1;
        }

        studentCounter += 1;
    }

    cout << "Passed: " << passes << "\nFailed: " << failures << "\n";

    if (passes > 8) {
        cout << "Bonus to instructor\n";
    }
}