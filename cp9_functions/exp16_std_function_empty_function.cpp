//
// Created by wbai on 11/23/2021.
//

/*
 * generic function pointer that wraps around callable object.
 *
 * You can store static function, function object, or a lambda into a std::function
 */

#include <cstdio>
#include <functional>


int main() {
    std::function<void()> func;
    try{
        func();
    } catch (const std::bad_function_call &e) {
        printf("Exception: %s", e.what());
    }
}