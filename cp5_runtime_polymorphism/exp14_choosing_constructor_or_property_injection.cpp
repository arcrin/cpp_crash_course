//
// Created by andy- on 2021-11-11.
//

/*
 * Whether you choose constructor or property injection depends on design requirements. If you need to be able to
 * modify underlying types of an object's members throughout the object's life cycle, you should choose pointers and the
 * property injector method. But the flexibility of using pointers and property injection comes at a cost. In the
 * Bank example in this chapter, you must make sure that you either don't set logger to nullptr or that you check for
 * this condition before using logger. There's also the question of what the default behavior is: what is the initial
 * value of logger?
 *
 * One possibility is to provide constructor and property injection. This encourages anyone who uses your class to
 * think about initializing it.
 */

#include <cstdio>

struct Logger {
    virtual ~Logger() = default;

    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[con] %ld -> %ld: %f\n", from, to, amount);
    }
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld, %ld, %f\n", from, to, amount);
    }
};

struct Bank {
    Bank(Logger* logger) : logger{logger} {}
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }
    void make_transfer(long from, long to, double amount) {
        if (logger) logger->log_transfer(from, to, amount);
    }
private:
    Logger *logger;
};