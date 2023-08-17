//

#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<double> doubleStack{};
    constexpr size_t doubleStackSize{5};
    double doubleValue{1.1};

    cout << "Pushing elements onto doubleStack\n";

    for (size_t i{0}; i < doubleStackSize; ++i) {
        doubleStack.push(doubleValue);
        cout << doubleValue << ' ';
        doubleValue += 1.1;
    }

    cout << "\n\nPopping elements from doubleStack\n";

    // pop elements from doubleStack
    while (!doubleStack.isEmpty()) {
        cout << doubleStack.top() << ' '; // display top element
        doubleStack.pop(); // remove top element
    }

    cout << "\nStack is empty, cannot pop.\n";

    Stack<int> intStack{}; // create a Stack of int
    constexpr size_t intStackSize{10}; // stack size
    int intValue{1}; // first value to push

    cout << "\nPushing elements onto intStack\n";

    // pushing 10 integers onto intStack
    for (size_t i{0}; i < intStackSize; ++i) {
        intStack.push(intValue);
        cout << intValue++ << ' ';
    }

    cout << "\n\nPopping elements from intStack\n";

    // pop elements from intStack
    while (!intStack.isEmpty()) { // loop while stack is not empty
        cout << intStack.top() << ' '; // display top element
        intStack.pop(); // remove top element
    }
    cout << "\nStack is empty, cannot pop.\n";
}