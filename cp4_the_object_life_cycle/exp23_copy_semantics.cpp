//
// Created by andy- on 2021-11-06.
//

/*
 * Copy semantics is "the meaning of copy." In practice, programmers use the term to mean the rules for making copies
 * of objects: after x is copied into y, they are equivalent and independent. That is, x == y is true after a
 * copy (equivalence), and a modification to x doesn't cause a modification of y (independence).
 */

#include <cstdio>

struct Point {
    Point(int x, int y): x{x}, y{y} {}
    int x{}, y{};
    void show_coordinate() {
        printf("x: %d, y: %d\n", x, y);
    }
};

Point make_transpose(Point p) {
    int tmp = p.x;
    p.x = p.y;
    p.y = tmp;
    return p;
}

int add_one_to(int x) {
    x++;
    return x;
}

int main() {
    auto original = 1;
    auto result = add_one_to(original);
    printf("Original: %d; Result: %d\n", original, result);
    Point p1 = Point(1, 2);
    Point p2 = make_transpose(p1);
    p1.show_coordinate();
    p2.show_coordinate();
}