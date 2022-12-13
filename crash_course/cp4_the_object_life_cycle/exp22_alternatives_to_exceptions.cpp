//
// Created by andy- on 2021-11-06.
//

/*
 * In situations where exceptions are not available, all is not lost. Although you will need to keep track of errors
 * manually, there are some helpful C++ features that you can employ to take the sting out a bit.
 */

/*
 * First, you can manually enforce class invariants by exposing some method that communicates whether the class
 * invariants could be established
 */
struct HumptyDumpty {
    HumptyDumpty();

    bool is_together_again();
};

bool send_kings_horses_and_men() {
    HumptyDumpty hd{};
    if (hd.is_together_again()) return false;
    // Class invariants of hd are now guaranteed.
    // Humpty Dumpty had a great fall.
}

int main() {

}

/*
 * Second, complementary coping strategy is to return multiple values using structured binding declaration,
 * a language feature that allows you to return multiple values from a function call. You can use this feature
 * to return success flags alongside the usual return value.
 */

struct Result {
    HumptyDumpty hd;
    bool success;
};

Result make_humpty() {
    HumptyDumpty hd{};
    bool is_valid;
    // Check that hd is valid and set is_valid appropriately
    return {hd, is_valid};
}

bool send_kings_horses_and_men_2() {
    auto[hd, success] = make_humpty();
    if(!success) return false;
    // Class invariants established
    return true;
}