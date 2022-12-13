//
// Created by wbai on 11/3/2021.
//

/*
 * If only thread_local is specified, static is assumed.
 */

#include <cstdio>

void power_up_rat_thing(int nuclear_isotopes) {
    static thread_local int rat_things_power = 200;
    // --snip--
}