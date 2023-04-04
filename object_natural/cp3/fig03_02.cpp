//
// Created by wbai on 4/4/2023.
// sentinel-controlled iteration
//

#include <iostream>
#include <iomanip> // parameterized stream manipulators

using namespace std;

int main() {
    // initialization phase
    int total{0};
    int gradeCounter{0};

    cout << "Enter grade or -1 to quit:";
    int grade;
    cin >> grade;

    // loop until sentinel value is read from user
    while (grade != -1) {
        total = total + grade;
        gradeCounter += 1;

        cout << "Enter grade or -1 to quit: ";
        cin >> grade;
    }

    if (gradeCounter != 0) {
        double average{static_cast<double>(total) / gradeCounter};

        cout << "\nTotal of the " << gradeCounter << " grade entered is " << total;
        cout << setprecision(2) ;
        cout << "\nClass average is " << average << "\n";
    } else{
        cout << "No grades were entered\n";
    }
}
