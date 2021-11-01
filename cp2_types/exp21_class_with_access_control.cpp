//
// Created by andy- on 2021-10-31.
//

//struct ClockOfTheLongNow {
//    void add_year() {
//        year++;
//    }
//    bool set_year(int new_year){
//        if (new_year < 2019) return false;
//        year = new_year;
//        return true;
//    }
//    int get_year() {
//        return year;
//    }
//private:
//    int year;
//};            all struct members are public by default

#include <cstdio>

class ClockOfTheLongNow {
public:
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
}; // class members are private by default

int main() {
    ClockOfTheLongNow clock{};
    if(!clock.set_year(2018)){
        clock.set_year(2019);
    }
    clock.add_year();
    printf("year: %d", clock.get_year());
}