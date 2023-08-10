#include <iostream>
#include <queue>

int main() {
    std::priority_queue<double> priorities; // create priority_queue

    // push elements onto priorities
    priorities.push(3.2);
    priorities.push(9.8);
    priorities.push(5.4);

    std::cout << "Popping from priorities: ";

    // pop element from priority_queue
    while (!priorities.empty()) {
        std::cout << priorities.top() << ' ';
        priorities.pop(); // remove top element
    }

    std::cout << "\n";
}