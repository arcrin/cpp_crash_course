//
// Created by wbai on 7/20/2023.
//
#include "Time.h"

int main() {
    Time wakeUp{6, 45, 0};
    const Time noon{12, 0, 0};

    wakeUp.setHour(18);
    noon.setHour(12); // call non-const member function on a const object
    wakeUp.getHour();
    noon.getHour();
}