//
// Created by andy- on 2021-11-06.
//

/*
 * Often, the compiler will generate default implementations for copy construction and copy assignment.
 * The default implementation is to invoke construction or copy assignment on each of a class's members.
 *
 * Any time a class manages a resource, you must be extremely careful with default copy semantics; they're likely
 * to be wrong (as you saw with SimpleString). Best practice dictates that you explicitly declare that default copy
 * assignment and copy construction are acceptable for such classes using the "default" keyword.
 */

struct Replicant {
    Replicant(const Replicant &) = default;

    Replicant &operator=(const Replicant &) = default;
};

/*
 * Some classes simply cannot or should not be copied - for example, if your class manages a file or if it represents
 * a mutual exclusion lock for concurrent programming. You can suppress the compiler from generating a copy constructor
 * and a copy assignment operator using the "delete" keyword
 */

struct Highlander {
    Highlander(const Highlander &) = delete;

    Highlander &operator=(const Highlander &) = delete;
};

int main() {
    Highlander a;
    Highlander b{a}; // Bang! There can be only one.
}