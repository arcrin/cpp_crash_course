//
// Created by wbai on 4/4/2023.
// continue statement terminating an iteration of a for statement
//
#include <iostream>

using namespace std;

int main() {
    for (int count{1}; count <= 10; ++count) {
        if (count == 5) {
            continue;
        }

        cout << count << " ";
    }
    cout << "\nUsed continue to skip printing 5" << "\n";
}
