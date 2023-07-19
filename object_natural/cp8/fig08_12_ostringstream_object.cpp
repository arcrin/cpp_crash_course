//
// Created by andy- on 2023-07-16.
//
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ostringstream output; // create ostringstream object

    const std::string string1{"Output of several data types "};
    const std::string string2{"to an ostringstream object:"};
    const std::string string3{"\ndouble: "};
    const std::string string4{"\n int: "};

    constexpr double d{123.4567};
    constexpr int i{22};

    // output strings, double and int to ostringstream
    output << string1 << string2 << string3 << d << string4 << i;

    // call str to obtain string contents of the ostringstream
    std::cout << "output contains:\n" << output.str();

    // add additional characters and call str to output string
    output << "\nmore characters added";
    std::cout << "\n\noutput now contains:\n" << output.str() << '\n';
}