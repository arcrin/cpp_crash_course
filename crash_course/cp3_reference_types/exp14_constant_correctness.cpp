//
// Created by wbai on 11/2/2021.
//

#include <cstdio>

/*
 * constant argument
 */
void petruchio(const char* shrew) {
    printf("Fear not, sweet wench, they shall not touch thee, %s", shrew);
//    shrew[0] = "K"; // Compiler error! The shrew cannot be tamed.
}

/*
 * constant method, promise not to modify the current object's state within the const method. Read-only method
 */
struct ClockOfTheLongNow {
    int get_year() const {
        return year;
    }
    void set_year(int new_year){
        this->year = new_year;
    }
private:
    int year = 2019;
};

// const method can only invoke other const method
bool is_leap_year(const ClockOfTheLongNow& clock) {
    if (clock.get_year() % 4 > 0) return false;
    if (clock.get_year() % 100 > 0) return true;
    if (clock.get_year() % 400 > 0) return false;
    return true;
}

/*
 * const member variables
 */
struct Avout {
    const char* name = "Erasmas";
    ClockOfTheLongNow apert;
};

void does_not_compile(const Avout& avout) {
//    avout.apert.set_year(); // Compiler error: avout is const
}

int main() {
    ClockOfTheLongNow clock{};
    clock.set_year(2020);
    printf("%d is leap year %d\n", clock.get_year(), is_leap_year(clock));
}