#include <iostream>
#include <string>

int main() {
    const std::string s{"airplane"};
    std::cout << s.substr(3, 4) << '\n'; // retrieve substring "plan"
}