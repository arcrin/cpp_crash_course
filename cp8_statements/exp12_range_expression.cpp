//
// Created by wbai on 11/22/2021.
//

/*
 * You can define your own types that are also valid range expressions. But you will need to specify several
 * functions on your type.
 *
 * Every range exposes a "begin" and an "end" method. These functions represent the common interface that a range-based
 * for loop uses to interact with a range. Both methods return iterators. An iterator is an object that supports
 * operator!=, operator++, and operator*.
 */
#include <cstdio>

struct FibonacciIterator {
    bool operator!=(int x) const{
        return x >= current;
    }

    FibonacciIterator &operator++(){
        const auto tmp = current;
        current += last;
        last = tmp;
        return *this;
    }

    int operator*() const {
        return current;
    }

private:
    int current{1}, last{1};
};

struct FibonacciRange {
    explicit FibonacciRange(int max) : max{max} {}
    FibonacciIterator begin() const {
        return FibonacciIterator{};
    }
    int end() const {
        return max;
    }
private:
    const int max;
};

int main() {
    for (const auto i: FibonacciRange{5000}) {
        printf("%d ", i);
    }
}