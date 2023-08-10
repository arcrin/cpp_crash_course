#include <iostream>
#include <list>
#include <ranges>
#include <stack>
#include <vector>

// pushElements generic lambda to push values onto a stack
auto pushElements = [](auto& stack) {
    for (auto i: std::views::iota(0, 10)) {
        stack.push(i);
        std::cout << stack.top() << ' ';
    }
};

// popElements generic lambda to pop elements off a stack
auto popElements = [](auto& stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << ' '; // view (and display) top element
        stack.pop(); // remove top element
    }
};

int main() {
    std::stack<int> dequeStack{}; // uses a deque by default
    std::stack<int, std::vector<int>> vectorStack{}; // use a vector
    std::stack<int, std::list<int>> listStack{};

    // push the values 0-9 onto each stack
    std::cout << "Pushing onto dequeStack: ";
    pushElements(dequeStack);
    std::cout << "\nPushing onto vectorStack: ";
    pushElements(vectorStack);
    std::cout << "\nPushing onto listStack: ";
    pushElements(listStack);

    // display and remove elements from each stack
    std::cout << "\n\nPopping from dequeStack: ";
    popElements(dequeStack);
    std::cout << "\nPopping from vectorStack: ";
    popElements(vectorStack);
    std::cout << "\nPopping from listStack: ";
    popElements(listStack);
    std::cout << "\n";
}