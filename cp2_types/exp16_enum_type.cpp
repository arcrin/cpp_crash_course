//
// Created by andy- on 2021-10-31.
//

#include <cstdio>

enum class Race {
    Dinan,
    Teklan,
    Ivyn,
    Moiran,
    Camite,
    Julian,
    Aidan
};

int main() {
    Race langobard_race = Race::Aidan;
    printf("%d", langobard_race == Race::Aidan);
}