//
// Created by wbai on 11/22/2021.
//

/*
 * You can make an if statement constexpr; such statements are known as constexpr if statement. A constexpr if statement
 * is evaluated at compile time. Code blocks that correspond to true conditions get emitted, and the rest is ignored.
 */

#include <cstdio>
#include <stdexcept>
#include <type_traits>


template<typename T>
auto value_of(T x){
    if constexpr(std::is_pointer<T>::value) {
        if(!x) throw std::runtime_error{"Null pointer dereference."};
        return *x;
    } else {
        return x;
    }
}

int main(){
    unsigned long level{8998};
    auto level_ptr = &level;
    auto &level_ref = level;
    printf("Power level = %lu\n", value_of(level_ptr));
    ++*level_ptr;
    printf("Power level = %lu\n", value_of(level_ptr));
    ++level_ref;
    printf("It's over %lu\n", value_of(level++));
    try{
        level_ptr = nullptr;
        value_of(level_ptr);
    } catch (const std::exception &e) {
        printf("Exception: %s\n", e.what());
    }
}

/*
 * At runtime, the constexpr if statement disappears; each instantiation of value_of contains one branch of the
 * selection statement or the other. You might be wondering why such a facility is useful. Compile time evaluation
 * can substantially simplify your programs by eliminating magic values (manually calculated constants copy and pasted
 * directly into source code).
 *
 *
 */