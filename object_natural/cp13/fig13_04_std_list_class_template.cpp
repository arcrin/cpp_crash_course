//
// Created by wbai on 8/10/2023.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <typename T>
void printList(const std::list<T>& items) {
    if (items.empty()) {
        std::cout << "List is empty";
    }
    else {
        std::ostream_iterator<T> output{std::cout, " "};
        std::ranges::copy(items, output);
    }
}

int main() {
    std::list<int> values{}; // create list of ints

    // insert items in values
    values.push_front(1);
    values.push_front(2);
    values.push_back(4);
    values.push_back(3);

    std::cout << "values contains: ";
    printList(values);

    values.sort();
    std::cout << "\nvalues after sorting contains: ";
    printList(values);

    // insert elements of ints into otherValues
    std::vector ints{2, 6, 4, 8};
    std::list<int> otherValues{};
    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    std::cout << "\nAfter insert, otherValues contains: ";
    printList(otherValues);

    // remove otherValues elements and insert at end of values
    values.splice(values.cend(), otherValues); // cend() actually points to last element + 1; splice empties otherValues
    std::cout << "\nAfter splice, values contains: ";
    printList(values);

    values.sort();
    std::cout << "\nAfter sort, values contains: ";
    printList(values);

    // insert elements of ints into otherValues
    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    otherValues.sort();
    std::cout << "\nAfter insert and sort, otherValues contains: ";
    printList(otherValues);

    // remove otherValues elements and insert into values in sorted order
    values.merge(otherValues); // empties otherValues
    std::cout << "\nAfter merge:\n values contains: ";
    printList(values);
    std::cout << "\n otherValues contains: ";
    printList(otherValues);

    values.pop_front();
    values.pop_back();
    std::cout << "\nAfter pop_front and pop_back:\n values contains: ";
    printList(values);

    values.unique();
    std::cout << "\nAfter unique, values contains: ";
    printList(values);

    values.swap(otherValues);
    std::cout << "\nAfter swap:\n values contains: ";
    printList(values);
    std::cout << "\n otherValues contains: ";
    printList(otherValues);

    // replace contents of values with elements of otherValues
    values.assign(otherValues.cbegin(), otherValues.cend());
    std::cout << "\nAfter assign:";
    std::cout << "\n values contains: ";
    printList(values);
    std::cout << "\n otherValues contains: ";
    printList(otherValues);

    // remove otherValues elements and insert into values in sorted order
    values.merge(otherValues);
    std::cout << "\nAfter merge, values contains: ";
    printList(values);

    values.remove(4); // remove all 4s
    std::cout << "\nAfter remove(4), values contains: ";
    printList(values);
    std::cout << "\n";
}