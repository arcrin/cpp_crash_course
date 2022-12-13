//
// Created by wbai on 11/12/2021.
//

/*
 * The static_cast reverses a well-defined implicit conversion, such as an integer type to another integer type.
 * The object-to-cast is of some type that the desired-type implicitly converts to. The reason you might need
 * static_cast is that, generally, implicit casts aren't reversible.
 */

#include <cstdio>

short increment_as_short(void* target) {
    auto as_short = static_cast <short *>(target);
    *as_short = *as_short + 1;
    return *as_short;
}

int main() {
    short beast{665};
    auto mark_of_the_beast = increment_as_short(&beast);
    printf("%d is the mark_of_the_beast.", mark_of_the_beast);
    /*
     * implicit conversion of short* to void* is well-defined. Attempting ill-defined conversions with static_cast,
     * such as converting a char* to a float*, will result in a compiler error:
     */
    float on = 3.5166666666;
    auto not_alright = static_cast<char *>(&on); // Compiler error
}