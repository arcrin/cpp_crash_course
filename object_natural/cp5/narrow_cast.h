//
// Created by wbai on 4/6/2023.
//

#ifndef CPP_CRASH_COURSE_NARROW_CAST_H
#define CPP_CRASH_COURSE_NARROW_CAST_H
#include <stdexcept>

template<class T, class U>
T narrow_cast(U u) {
    T t = static_cast<T>(u);
    if (static_cast<U>(t) != u) {
        throw std::runtime_error("narrow_cast failed");
    }
    return t;
}


#endif //CPP_CRASH_COURSE_NARROW_CAST_H
