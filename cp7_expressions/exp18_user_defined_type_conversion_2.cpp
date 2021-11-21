//
// Created by andy- on 2021-11-20.
//

/*
 * Sometimes, implicit conversions can cause surprising behavior. You should always try to use explicit conversions,
 * especially with user-defined types. You can achieve explicit conversions with the explicit keyword. Explicit
 * constructors instruct the compiler not to consider the constructor as a means for implicit conversion. You can
 * provide the same guidelines for your user-defined conversion functions:
 */
#include <cstdio>

struct ReadOnlyInt {
    ReadOnlyInt(int val) : val {val} {}
    explicit operator int() const {
        return val;
    }
private:
    const int val;
};
// Now, you must explicitly cast a ReadOnlyInt to an int using static_cast
int main() {
    ReadOnlyInt the_answer{42};
    auto ten_answers = static_cast<int>(the_answer) * 10;
    printf("ten answers: %d", ten_answers);
}
/*
 * Generally, this approach tends to promote less ambiguous code.
 */