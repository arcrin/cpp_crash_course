//
// Created by andy- on 2021-10-31.
//

#include <cstdio>

class ClockOfTheLongNow {
public:
    ClockOfTheLongNow(int year_input){
        if(!set_year(year_input)){
            year = 2019;
        };
    };
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
    int year;
};

int main() {
    ClockOfTheLongNow clock{2020};
    printf("Default year: %d", clock.get_year());
}