#include <fmt/format.h>
#include <iostream>
#include <string>

int main() {
    std::string s1{"cat"};
    std::string s2; // initialized to the empty string
    std::string s3; // initialized to the empty string

    s2 = s1; // assign s1 to s2
    s3.assign(s1); // assign s1 to s3
    std::cout << fmt::format("s1: {}\ns2: {}\ns3: {}\n\n", s1, s2, s3);

    s2.at(0) = 'r'; // modify s2
    s3.at(2) = 'r'; // modify s3
    std::cout << fmt::format("After changes: \ns2: {}\ns3: {}", s2, s3);

    std::cout << "\n\nAfter concatenations:\n";
    std::string s4{s1 + "apult"}; //concatenation
    s1.append("acomb"); // create "catacomb"
    s3 += "pet"; // create "carpet" with overloaded +=
    std::cout << fmt::format("s1: {}\ns3: {}\ns4: {}\n", s1, s3, s4);

    // append locations 4 through end of s1 to
    // create string "comb" (s5 was initially empty)
    std::string s5; //initialized to the empty string
    s5.append(s1, 3, s1.size() - 3);
    std::cout << fmt::format("s5: {}", s5);
}