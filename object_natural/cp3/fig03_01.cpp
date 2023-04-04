//
// Created by wbai on 4/4/2023.
// counter-controlled iteration
//
#include <iostream>
using namespace std;

int main() {
    // initialization phase
    int total{0};
    int gradeCounter{0}; // initialize grade # to be entered next

    // processing phase uses counter-controlled iteration
    while (gradeCounter <= 10) {
        cout << "Enter grade: ";
        int grade;
        cin >> grade; // input next grade
        total = total + grade; // add grade to taotal
        gradeCounter = gradeCounter + 1; // increment counter by
    }

    // termination phase
    int average{total / 10}; // int division yields int result

    // display total and average of grades
    cout << "\nTotal of all 10 grades is " << total;
    cout << "\nClass average is " << average << "\n";
};