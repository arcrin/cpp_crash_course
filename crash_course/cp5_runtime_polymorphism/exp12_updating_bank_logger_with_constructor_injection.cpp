//
// Created by andy- on 2021-11-11.
//

/*
 * The Logger interface allows you to provide multiple logger implementations. This allows a Logger consumer to log
 * transfers with the log_transfer method without having to know the logger's implementation details.
 */

/*
 * Using constructor injection, you have a Logger reference that you pass into the Bank class's constructor. This way,
 * you establish the kind of logging that a particular Bank instantiation will perform.
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
    Bank(Logger& logger) : logger{logger} {}
    void make_transfer(long from, long to, double amount) {
        logger.log_transfer(from, to, amount);
    }
private:
    Logger &logger;
};

int main() {
    ConsoleLogger logger;
    Bank bank{logger};
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
}