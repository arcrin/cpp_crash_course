//
// Created by wbai on 11/13/2021.
//

#include <cstddef>
#include <cstdio>

double mean_double_values(const double *values, size_t length) {
    double result{};
    for(size_t i{}; i < length; i++) {
        result += values[i];
    }
    return result / length;
}

long mean_long_values(const long* values, size_t length) {
    long result{};
    for(size_t i{}; i < length; i++) {
        result += values[i];
    }
    return result / length;
}

template<typename T>
T mean(const T* values, size_t length) {
    T result{};
    for(size_t i{}; i < length; i++) {
        result += values[i];
    }
    return result / length;
}

//int main() {
//    const double nums_d[]{1.0, 2.0, 3.0, 4.0};
//    const auto result1 = mean<double>(nums_d, 4);
//    printf("double: %f\n", result1);
//
//    const float nums_f[]{1.0f, 2.0f, 3.0f, 4.0f};
//    const auto result2 = mean<float>(nums_f, 4);
//    printf("float: %f\n", result2);
//
//    const size_t nums_c[]{1, 2, 3, 4};
//    const auto result3 = mean<size_t>(nums_c, 4);
//    printf("size_t: %zu\n", result3);
//}

/*
 * You might have noticed that you had to type the pointed-to array twice: once to declare an array and again to specify
 * a template parameter. This gets tedious and can cause errors. If the template parameter doesn't match, you will get a
 * compiler error or cause unintended casting.
 *
 * Fortunately, you can generally omit the template parameters when invoking a template function. The process that the
 * compiler uses to determine the correct template parameters is called template type deduction.
 */

/*
 * Template type deduction
 * Generally, you don't have to provide template function parameters. The compiler can deduce them from usage
 */

int main() {
    const double nums_d[]{1.0, 2.0, 3.0, 4.0};
    const auto result1 = mean(nums_d, 4);
    printf("double: %f\n", result1);

    const float nums_f[]{1.0f, 2.0f, 3.0f, 4.0f};
    const auto result2 = mean(nums_f, 4);
    printf("float: %f\n", result2);

    const size_t nums_c[]{1, 2, 3, 4};
    const auto result3 = mean(nums_c, 4);
    printf("size_t: %zu\n", result3);
}

/*
 * Sometimes, template arguments cannot be deduced. For example, if a template function's return type is a template
 * argument, you must specify template arguments explicitly.
 */
