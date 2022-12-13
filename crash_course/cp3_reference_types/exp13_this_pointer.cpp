//
// Created by wbai on 11/2/2021.
//

#include <cstdio>

struct Element {
    Element *next{};
    void insert_after(Element* new_element) {
        new_element->next = this->next;
        this->next = new_element;
    }

    char prefix[2];
    short operating_number;
};

struct ClcokOfTheLongNow {
    bool set_year(int year) {
        if (year < 2019) {
            this->year = year; //use this point to distinguish ambiguity
            return true;
        }
    }

private:
    int year;
};