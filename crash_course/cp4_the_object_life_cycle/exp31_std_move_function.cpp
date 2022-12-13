//
// Created by andy- on 2021-11-06.
//

#include <utility>
#include <cstdio>

void ref_type_l(int &x) {
    printf("lvalue reference %d\n", x);
}

void ref_type_r(int &&x) {
    printf("rvalue reference %d\n", x);
}

/*
 * You can cast an lvalue reference to an rvalue reference using the std::move function from the <utility> header.
 */

int main() {
    auto x = 1;
    ref_type(std::move(x));
    ref_type(2);
    ref_type(x + 2);
}

/*
 * Be very careful when you're using std::move, because you remove the safeguards keeping you from interacting with a
 * moved-from object. You can perform two actions on a moved-from object: destroy it or reassign it.
 *
 * How lvalue and rvalue semantics enable move semantics should now be clear. If an lvalue is at hand, moving is
 * suppressed. If an rvalue is at hand, moving is enabled.
 */

