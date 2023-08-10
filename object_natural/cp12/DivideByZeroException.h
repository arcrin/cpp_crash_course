//
// Created by wbai on 8/9/2023.
//

#ifndef CPP_CRASH_COURSE_DEVIDEBYZEROEXCEPTION_H
#define CPP_CRASH_COURSE_DEVIDEBYZEROEXCEPTION_H
#include <stdexcept>

// DivideByZeroException objects should be thrown
// by functions upon detecting division-by-zero
class DivideByZeroException : public std::runtime_error {
public:
    // constructor specifies default error message
    DivideByZeroException() : std::runtime_error{"attempted to divide by zero"} {}

};

#endif //CPP_CRASH_COURSE_DEVIDEBYZEROEXCEPTION_H
