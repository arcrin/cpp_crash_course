#include <fmt/format.h>
#include <iostream>
#include <string>

int main() {
    const std::string s{"noon is 12pm; midnight is not"};
    std::cout << "Original string: " << s;
    std::cout << fmt::format("\ns.find(\"is\"): {}\ns.rfind(\"is\"): {}", s.find("is"), s.rfind("is"));

    size_t location{s.find_first_of("misop")};
    std::cout << fmt::format("\ns.find_first_of(\"misop\") found {} at {}", s.at(location), location);

    // find '1' from beginning
    location = s.find_first_not_of("noi spm");
    std::cout << fmt::format("\ns.find_first_not_of(\"noi spm\") found {} at {}", s.at(location), location);

    // find ';' at location 12
    location = s.find_first_not_of("12noi spm");
    std::cout << fmt::format("\ns.find_first_not_of(\"12noi spm\") found {} at {}", s.at(location), location);

    // search for characters not in "noon is 12pm; midnight is not"
    location = s.find_first_not_of("noon is 12pm; midnight is not");
    std::cout << fmt::format("\n{}: {}\n",
                             "s.find_first_not_of(\"noon is 12pm; midnight is not\")",
                             location);
    std::cout << std::string::npos; // no position found
}