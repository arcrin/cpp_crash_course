//
// Created by wbai on 4/4/2023.
// counter-controlled iteration with the while iteration statement
//
#include <iostream>

using namespace std;

int main() {
    int counter{1};
    while (counter <= 10) {
        cout << counter << "    ";
        ++counter;
    }
    cout << "\n";
}