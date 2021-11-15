//
// Created by andy- on 2021-11-14.
//

/*
 * A template parameter declared with the typename (or class) keyword is called a type template parameter, which is a
 * stand-in for some yet-to-be-specified type. Alternatively, you can use non-type template parameters, which are
 * stand-ins for some yet-to-be-specified value. Non-type template parameters can be any of the following.
 */
#include <stdexcept>
#include <cstdio>

//int& get(int (&arr)[10], size_t index) {
//    if (index >= 10) throw std::out_of_range{"Out of bounds"};
//    return arr[index];
//}

template <size_t Index, typename T, size_t Length>
T& get(T (&arr)[Length]) {
    static_assert(Index < Length, "Out-of-bounds access");
    return arr[Index];
}

int main() {
    int fib[5]{1, 1, 2, 3, 5};
    printf("%d %d %d ", get<0>(fib), get<1>(fib), get<2>(fib));
    get<3>(fib) = get<1>(fib) + get<2>(fib); // template type deduction happening here
    printf("%d ", get<3>(fib));
    printf("%d ", get<4>(fib));
}