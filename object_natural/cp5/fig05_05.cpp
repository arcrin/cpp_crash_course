//
// Created by wbai on 2/6/2023.
// scoped enum
//
#include <fmt/format.h>
#include <iostream>
#include <random>

using namespace std;

int rollDice();

int main() {
    // scoped enumeration with constants that represent the game status
    enum class Status {keepRolling, won, lost};

    int myPoint{0}; // point if no win or loss on first roll
    Status gameStatus{Status::keepRolling}; // game is not over

    // determine game status and point (if needed) based on first roll
    switch (const int sumOfDice{rollDice()}) {
        case 7:
        case 11:
            gameStatus = Status::won;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = Status::lost;
            break;
        default:
            myPoint = sumOfDice;
            cout << fmt::format("Point is {}\n", myPoint);
            break;
    }
    // while game is not complete
    while (gameStatus == Status::keepRolling) { // not won or lost
        // roll dice again and determine game status
        if (const int sumOfDice{rollDice()}; sumOfDice == myPoint) {
            gameStatus = Status::won;
        } else if (sumOfDice == 7) { // lose by rolling 7 before point
            gameStatus = Status::lost;
        }
    }
    // display won or lost message
    if (Status::won == gameStatus) {
        cout << "Player wins\n";
    } else {
        cout << "Player loses\n";
    }
}

// roll dice, calculate sum and display results
int rollDice() {
    // set up random-number generation
    static random_device rd; // used to seed the default_random_engine
    static default_random_engine engine{rd()}; // rd() produces a seed
    static uniform_int_distribution randomDie{1, 6};

    const int die1{randomDie(engine)}; // first die roll
    const int die2{randomDie(engine)}; // second die roll
    const int sum{die1 + die2}; // compute sum of die values

    // display results of this roll
    cout << fmt::format("Player rolled {} + {} = {}\n", die1, die2, sum);

    return sum;
}