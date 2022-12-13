//
// Created by andy- on 2021-11-21.
//

/*
 * Namespaces prevent naming conflict
 *
 * Global namespace
 *
 * Place symbols within a namespace block
 *
 * Nested namespaces
 *
 * scope-resolution operator
 */

#include <cstdio>

namespace BroopKidron13::Shaltanac {
    enum class Color {
        Mauve,
        Pink,
        Russet
    };
}

int main() {
    const auto shaltanac_grass{BroopKidron13::Shaltanac::Color::Russet};
    if (shaltanac_grass == BroopKidron13::Shaltanac::Color::Russet) {
        printf("The other Shaltanac's joopleberry shrub is always "
               "a more mauvey shade of pinky russet.");
    }
}