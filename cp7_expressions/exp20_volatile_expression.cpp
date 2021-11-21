//
// Created by andy- on 2021-11-20.
//

/*
 * The volatile keyword tells the compiler that every access made through this expression must be treated as a visible
 * side effect. This means access cannot be optimized out or reordered with another visible side effect. This keyword is
 * crucial in some settings, like embedded programming, where reads and writes to some special portions of memory have
 * effects on the underlying system. The volatile keyword keeps the compiler from optimizing such access away.
 */

int foo(volatile int& x) {
    x = 10;
    x = 20;
    auto y = x;
    y = x;
    return y;
}

/*
 * A common misconception is that volatile has to do with concurrent programming. It does not. Variables marked volatile
 * are not generally thread safe. Part II discusses std::atomic, which guarantees certain thread safe primitives on
 * types. Too often, volatile is confused with atomic.
 */