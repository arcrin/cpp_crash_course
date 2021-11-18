//
// Created by wbai on 11/17/2021.
//

/*
 * Floating-point numbers can be implicitly cast to and from other floating-point numbers. As long as the destination
 * value can fit the source value, all is well. When it cannot, you have undefined behavior. Again, braced
 * initialization can prevent potentially dangerous conversions.
 */

#include <limits>
#include <cstdio>

int main() {
    double x = std::numeric_limits<float>::max();
    long double y = std::numeric_limits<double>::max();
    float z = std::numeric_limits<long double>::max(); // undefined behavior
    printf("x: %g\ny: %Lg\nz: %g", x, y, z);
}
