//
// Created by wbai on 11/2/2021.
//

#include <cstdio>

struct ClockOfTheLongNow {
    ClockOfTheLongNow(long new_year)
        :year{new_year}{
    }
    int get_year() const {
        return this->year;
    }
    void set_year(int new_year) {
        this->year = new_year;
    }
private:
    int year;
};

struct Avout {
    Avout(const char* name, long year_of_apert)
        : name{name}, apert{year_of_apert} {
    }
    void announce() const {
        printf("My name is %s and my next apert is %d.\n", name, apert.get_year());
    }
    const char* name;
    ClockOfTheLongNow apert;
};

int main() {
    Avout raz{"Erasmas", 3010};
    Avout jad{"Jad", 4000};
    raz.announce();
    jad.announce();
}