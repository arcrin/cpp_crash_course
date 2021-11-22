//
// Created by andy- on 2021-11-21.
//

/*
 * type alias is a different name given to a defined type; think of it as a label
 */

#include <cstdio>

namespace BroopKidron13::Shaltanac {
    enum class Color {
        Mauve,
        Pink,
        Russet
    };
}

using String = const char[260];
using ShaltanacColor = BroopKidron13::Shaltanac::Color;

int main() {
    const auto my_color{ShaltanacColor::Russet};
    String saying {
        "The other Shaltanac's joopleberry shrub is "
        "always a more mauvey shade of pinky russet."
    };
    if (my_color == ShaltanacColor::Russet) {
        printf("%s", saying);
    }
}