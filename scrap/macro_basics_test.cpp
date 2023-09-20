//
// Created by wbai on 9/14/2023.
//
#include <iostream>
#include <string>
#include <fmt/format.h>

#define PRINT_ARG_VALUES(...) std::cout << #__VA_ARGS__ << " = " << fmt::format("{}, {}, {}", ##__VA_ARGS__) << std::endl

#define CONCAT(a, b) a ## b

#define LOG(str_format, ...) std::cout << fmt::format(str_format, ##__VA_ARGS__)

#define GETTER(type, varName) type get_##varName() const { return varName;}

#define LOG_MESSAGE_PREFIX(prefix, ...) \
    std::cout << prefix << __VA_OPT__(" - " << __VA_ARGS__ <<) std::endl
#define M(X, ...) X __VA_OPT__(, ) __VA_ARGS__

class MyClass {
public:
    GETTER(int, value)
    GETTER(double, pi)
private:
    int value = 42;
    double pi = 3.14159;
};

int main() {
    int x = 10;
    double y = 3.14;
    const char *s = "hello";
#if 0
    MyClass obj;
    std::cout << "Value: " << obj.get_value() << std::endl;
    std::cout << "Pi: " << obj.get_pi() << std::endl;
#endif

#if 1
    LOG("x = {}, y = {}, s = {}\n", x, y, s);
    LOG("No argument\n");
#endif

#if 0
    PRINT_ARG_VALUES(x, y, s);
#endif

#if 1
    LOG_MESSAGE_PREFIX("[INFO]", "This is an informational message.");
    LOG_MESSAGE_PREFIX("[ERROR]");
//    LOG_MESSAGE_PREFIX("[DEBUG]", "Message A", "Message B");
#endif

#if 1
    std::cout << fmt::format("{}", M(3));
#endif
}