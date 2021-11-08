//
// Created by andy- on 2021-11-06.
//

/*
 * If you throw an exception in a destructor, it absolutely must be caught within the destructor. Suppose
 * an exception is thrown, and during stack unwinding, another exception is thrown by a destructor during
 * normal cleanup. Now you have two exceptions in flight. How should C++ runtime handle such situation?
 *
 * You can have an opinion on the matter, but the runtime will call terminate.
 */

#include <cstdio>
#include <stdexcept>

struct CyberdyneSeries800 {
    CyberdyneSeries800() {
        printf("I'm a friend of Sarah Connor.");
    }
    ~CyberdyneSeries800() {
        throw std::runtime_error{"I'll be back."};
    }
};

int main() {
    try {
        CyberdyneSeries800 t800;
        throw std::runtime_error{"Come with me if you want to live"};
    } catch(const std::exception& e) {
        printf("Caught exception: %s\n", e.what());
    }
}

/*
 * As a general rule, treat destructor as if they were noexcept.
 */