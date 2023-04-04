//
// Created by wbai on 4/4/2023.
// break statement exiting a for statement
//
#include <iostream>

using namespace std;

int main() {
    int count;

    for (count = 1; count <= 10; ++count) {
        if (count == 5) {
            break;
        }

        cout << count << " ";
    }
    cout << "\nBroke out of loop at count = " << count << "\n";
}