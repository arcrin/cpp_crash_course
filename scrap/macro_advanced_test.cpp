//
// Created by wbai on 9/19/2023.
//

/*
 * To prevent recursion, cpp associate a bit with every macro that has been defined.
 * The bit reflects whether the macro is currently being replaced with its substitution
 * list, we can call it replacing bit.
 * Cpp furthermore associates a bit with each token in the input stream, signifying that
 * the token can never be macro-expanded. Let's call the latter bit the unavailable bit.
 * Initially, the replacing bit and unavailable bits are all clear.
 *
 * As cpp processes each input token T, it sets T's unavailable bit and decides whether
 * to macro-expand -- because it's a function-like macro not followed by "(" -- cpp still
 * sets the unavailable bit. Moreover, once the unavailable has been set on an input token,
 * it is never cleared.
 * 1.
 */

#include <iostream>

#define PARENS ()

#define EXPAND4(arg) arg
#define EXPAND3(arg) EXPAND4(EXPAND4(EXPAND4(EXPAND4(arg))))

enum EPOLL_EVENTS {
    EPOLLIN = 0x001,
#define EPOLLIN EPOLLIN
    EPOLLPRI = 0x002,
#define EPOLLPRI EPOLLPRI
    EPOLLOUT = 0x003,
#define EPOLLOUT EPOLLOUT
};

#define FL(x) ((x) + 1)
#define ID(arg) arg
#define ID2(arg) arg

int main() {
//    std::cout << EXPAND3("hello") << std::endl;
//    std::cout << EPOLLIN << std::endl;
    std::cout << ID(ID)(ID)("test") << std::endl;
    std::cout << ID(ID2)(ID)("test") << std::endl;
}

