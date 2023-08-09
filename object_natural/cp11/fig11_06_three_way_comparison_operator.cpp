// Created by andy- on 2023-08-04.
#define FMT_HEADER_ONLY
#include <compare>
#include <fmt/format.h>
#include <iostream>
#include <string>

class Time {
public:
    Time(int hr, int min, int sec) noexcept
    : m_hr{hr}, m_min{min}, m_sec{sec}{}

    [[nodiscard]] std::string toString() const {
        return fmt::format("hr={}, min={}, sec={}", m_hr, m_min, m_sec);
    }

    // <=> operator automatically supports equality/relational operators
    auto operator<=>(const Time &t) const noexcept = default;

private:
    int m_hr;
    int m_min;
    int m_sec;
};

int main() {
    const Time t1(12, 15, 30);
    const Time t2(12, 15, 30);
    const Time t3(6, 30, 0);

    std::cout << fmt::format("t1: {}\nt2: {}\nt3: {}\n\n",
                             t1.toString(), t2.toString(), t3.toString());
    // using the equality and relational operators
    std::cout << fmt::format("t1 == t2: {}\n", t1 == t2);
    std::cout << fmt::format("t1 != t2: {}\n", t1 != t2);
    std::cout << fmt::format("t1 < t2: {}\n", t1 < t2);
    std::cout << fmt::format("t1 <= t2: {}\n", t1 <= t2);
    std::cout << fmt::format("t1 > t2: {}\n", t1 > t2);
    std::cout << fmt::format("t1 >= t2: {}\n\n", t1 >= t2);

    std::cout << fmt::format("t1 == t3: {}\n", t1 == t3);
    std::cout << fmt::format("t1 != t3: {}\n", t1 != t3);
    std::cout << fmt::format("t1 < t3: {}\n", t1 < t3);
    std::cout << fmt::format("t1 <= t3: {}\n", t1 <= t3);
    std::cout << fmt::format("t1 > t3: {}\n", t1 > t3);
    std::cout << fmt::format("t1 >= t3: {}\n\n", t1 >= t3);

    // using <=> to perform comparisons
    if ((t1 <=> t2) == nullptr) {
        std::cout << "t1 is equal to t2\n";
    }

    if ((t1 <=> t3) > nullptr) {
        std::cout << "t1 is greater than t3\n";
    }

    if ((t3 <=> t1) < nullptr) {
        std::cout << "t3 is less than t1\n";
    }
}