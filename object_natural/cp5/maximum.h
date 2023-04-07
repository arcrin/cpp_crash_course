//
// Created by wbai on 4/5/2023.
//

#ifndef CPP_CRASH_COURSE_MAXIMUM_H
#define CPP_CRASH_COURSE_MAXIMUM_H

template <typename T> // or template <class T>
T maximum(T value1, T value2, T value3) {
    T maximumValue{value1}; // assume value 1 is maximum

    // determine whether value2 is greater than maximumValue
    if (value2 > maximumValue) {
        maximumValue = value2;
    }

    // determine whether value3 is greater than maximumValue
    if (value3 > maximumValue) {
        maximumValue = value3;
    }
    return maximumValue;
}

#endif //CPP_CRASH_COURSE_MAXIMUM_H
