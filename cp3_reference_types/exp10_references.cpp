//
// Created by wbai on 11/2/2021.
//

/*
 *  References are safer, more convenient versions of pointers. References are declared
 *  with & appended to the type name.
 *  References cannot be assigned to null, and they cannot be reseated (or reassigned).
 *  These eliminate some bugs endemic to pointers.
 */


#include <cstdio>

struct ClockOfTheLongNow {
    void add_year() {
        year++;
    }
    bool set_year(int new_year){
        if (new_year < 2019) return false;
        year = new_year;
        return true;
    }
    int get_year() {
        return year;
    }
private:
    int year = 2019;
};

void add_year(ClockOfTheLongNow& clock) {
    clock.set_year(clock.get_year() + 1);
}

int main() {
    ClockOfTheLongNow clock{};
    printf("The year is %d.\n", clock.get_year());
    add_year(clock);
    printf("The year is %d.\n", clock.get_year());
}