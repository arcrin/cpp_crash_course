// fit15_17
// Repeating a task using the comma operator and fold expressions
#include <iostream>

template <typename... Items>
void printItems(Items... items) {
    ((std::cout << items << "\n"), ...);
}

int main () {
    std::cout << "printItems(1, 2.2, \"hello\"):\n";
    printItems(1, 2.2, "hello");
}