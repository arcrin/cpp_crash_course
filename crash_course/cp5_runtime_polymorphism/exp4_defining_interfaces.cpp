//
// Created by wbai on 11/9/2021.
//

/*
 * Unfortunately, there is no interface keyword C++. You have to define interfaces using antiquated inheritance
 * mechanisms.
 */

#include <cstdio>

struct Logger {
    virtual ~Logger() = default;

    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger: Logger{
    void log_transfer(long from, long to, double amount) override {
        printf("%d -> %ld: %f\n", from, to, amount);
    }
};

