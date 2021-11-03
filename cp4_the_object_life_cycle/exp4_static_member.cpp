//
// Created by wbai on 11/3/2021.
//

/*
 * Static members are members of a class that aren't associated with a particular instance of the class.
 * Normal class members have lifetimes nested within the class's lifetime, but static members have static
 * storage duration.
 *
 * These members are essentially similar to static variables and functions declared at global scope;
 * however, you must refer to them by the containing class's name, using the scope resolution operator ::/
 * In fact, you must initialize static members at global scope. You cannot initialize a static member within a
 * containing class definition.
 */

#include <cstdio>

struct RatThing {
    static int rat_things_power;
    static void power_up_rat_thing(int nuclear_isotopes) {
        rat_things_power = rat_things_power = nuclear_isotopes;
        const auto waste_heat = rat_things_power * 20;
        if (waste_heat > 10000) {
            printf("Warning! Hot\n");
        }
        printf("Rat-thing power: %d\n", rat_things_power);
    }
};

int RatThing::rat_things_power = 200;

int main() {
    RatThing::power_up_rat_thing(100);
    RatThing::power_up_rat_thing(500);
}