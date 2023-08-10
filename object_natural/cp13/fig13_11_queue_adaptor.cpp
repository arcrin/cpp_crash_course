#include <iostream>
#include <queue>

int main() {
    std::queue<double> values{};

    values.push(3.2);
    values.push(9.8);
    values.push(5.4);

    std::cout << "Popping from values: ";

    // pop elements from queue
    while (!values.empty()) {
        std::cout << values.front() << ' '; // view front element
        values.pop(); // remove element
    }

    std::cout << "\n";
}