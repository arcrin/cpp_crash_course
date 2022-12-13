//
// Created by andy- on 2021-11-13.
//

#include <stdexcept>
#include <type_traits>

/*
 * Concepts are fairly heavyweight mechanisms for enforcing type safety. Sometimes, you just want to enforce some
 * requirements directly in the template prefix. You can embed requires expressions directly into the template
 * definition to accomplish this.
 */

template<typename T>
requires std::is_copy_constructible<T>::value
T get_copy(T* pointer) {
    if (!pointer) throw std::runtime_error{"Null-pointer dereference"};
    return *pointer;
}

struct Highlander {
    Highlander() = default;

    Highlander(const Highlander &) = delete;
};

int main() {
    Highlander connor;
    auto connor_ptr = &connor;
    auto connor_copy = get_copy(connor_ptr);
}