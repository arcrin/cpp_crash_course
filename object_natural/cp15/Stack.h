//
// Created by wbai on 8/14/2023.
//

#ifndef CPP_CRASH_COURSE_STACK_H
#define CPP_CRASH_COURSE_STACK_H
#pragma once
#include <deque>

template<typename T>
class Stack {
public:
    // return the top element of Stack
    const T& top() const { return stack.front(); }

    // push an element onto Stack
    void push(const T& pushValue) { stack.push_front(pushValue); }

    // pop an element from Stack
    void pop() { stack.pop_front(); }

    // determine whether Stack is empty
    [[nodiscard]] bool isEmpty() const { return stack.empty(); }

    // return size of Stack
    [[nodiscard]] size_t size() const { return stack.empty(); }

private:
    std::deque<T> stack{};
};


#endif //CPP_CRASH_COURSE_STACK_H
