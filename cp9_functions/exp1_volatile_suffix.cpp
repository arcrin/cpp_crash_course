//
// Created by wbai on 11/23/2021.
//

/*
 * The volatile keyword indicates that a method can be invoked on volatile objects. This is analogous to how const
 * methods can be applied to const objects. Together, these two keywords define a method's const/volatile qualification
 * (or sometimes cv qualification
 */
#include <cstdio>

struct Distillate {
    int apply() volatile{
        return ++applications;
    }

private:
    int applications{};
};

int main() {
    volatile Distillate ethanol;
    printf("%d Tequila\n", ethanol.apply());
    printf("%d Tequila\n", ethanol.apply());
    printf("%d Tequila\n", ethanol.apply());
    printf("Floor!");
}

/*
 * Just like you cannot invoke non-const method on const object, you cannot not invoke a non-volatile method on a
 * volatile object.
 */