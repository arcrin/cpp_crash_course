//
// Created by wbai on 8/1/2023.
//
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::string s1{"happy"};
    std::string s2{"birthday"};
    std::string s3;
    std::string_view v{"hello"};

    std::cout << "s1: \"" << s1 << "\"; s2: \"" << s2
    << "\"; s3: \"" << s3 << "\"; v: \"" << v << "\"\n\n";

    std::cout << "The results of comparing s2 and s1:\n"
        << fmt::format("s2 == s1: {}\n", s2 == s1)
        << fmt::format("s2 != s1: {}\n", s2 != s1)
        << fmt::format("s2 > s1: {}\n", s2 > s1)
        << fmt::format("s2 < s1: {}\n", s2 < s1)
        << fmt::format("s2 >= s1: {}\n", s2 >= s1)
        << fmt::format("s2 <= s1: {}\n\n", s2 <= s1);

    std::cout << "Testing s3.empty():\n";

    if (s3.empty()) {
        std::cout << "s3 is empty; assigning s1 to s3; \n";
        s3 = s1; // assign s1 to s3, overloaded copy assignment operator
        std::cout << fmt::format("s3 is \" {}\"\n\n", s3);
    }

    s1 += s2;
    std::cout << fmt::format("s1 += s2 yields s1 = {}\n\n", s1);

    s1 += " to you";
    std::cout << fmt::format("s1 += \" to you\" yields s1 = {}\n\n", s1);

    using namespace std::string_literals;
    s1 += ", have a great day!"s; // string-literal object
    std::cout << fmt::format(
            "s1 += \", have a great day!\"s yields\ns1 = {}\n\n", s1);
}