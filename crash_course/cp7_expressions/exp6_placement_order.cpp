//
// Created by wbai on 11/17/2021.
//

/*
 * Placement Order
 *
 * Sometimes, you don't want to override all free store allocations. In such situations, you can use the placement
 * operators, which perform the appropriate initialization on pre-allocated memory:
 *  1. void* operator new(size_t, void*)
 *  2. void operator delete(size_t, void*)
 *  3. void* operator new[](void*, void)
 *  4. void operator delete[](void*, void)
 *
 *  Using placement operators, you can manually construct objects in arbitrary memory. This has the advantage of
 *  enabling you to manually you to manually manipulate an object's lifetime. However, you cannot use delete to release
 *  the resulting dynamic objects. You must call the object's destructor directly (and exactly once!)
 */

#include <cstdio>
#include <cstddef>
#include <new>

struct Point{
    Point() : x{}, y{}, z{} {
        printf("Point at %p construced.\n", this);
    }
    ~Point() {
        printf("Point at %p destructed.\n", this);
    }
    double x, y, z;
};

int main() {
    const auto point_size = sizeof(Point);
    std::byte data[3 * point_size];
    printf("Data starts at %p.\n", data);
    auto point1 = new(&data[0 * point_size]) Point{};
    auto point2 = new(&data[1 * point_size]) Point{};
    auto point3 = new(&data[2 * point_size]) Point{};
    point1->~Point();
    point2->~Point();
    point3->~Point();
}