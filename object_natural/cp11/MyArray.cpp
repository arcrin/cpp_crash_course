// MyArray.cpp
// MyArray class member- and friend-function definitions
#define FMT_HEADER_ONLY
#include <algorithm>
#include <fmt/format.h>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <span>
#include <sstream>
#include <stdexcept>
#include <utility>
#include "MyArray.h"

MyArray::MyArray(size_t size)
        : m_size{size},
          m_ptr{std::make_unique<int[]>(size)} {
    std::cout << "MyArray constructor with size\n";
}

// MyArray constructor that accepts an initializer list
MyArray::MyArray(std::initializer_list<int> list)
        : m_size(list.size()), m_ptr{std::make_unique<int[]>(list.size())} {
    std::cout << "MyArray constructor with initializer list\n";

    // copy list argument's elements into m_ptr's underlying int array
    // m_ptr.get() returns the int array's starting memory location
    std::copy(std::begin(list), std::end(list), m_ptr.get());
}

// copy constructor: must receive a reference to a MyArray
MyArray::MyArray(const MyArray &original)
        : m_size{original.size()},
          m_ptr{std::make_unique<int[]>(original.size())} {
    std::cout << "MyArray copy constructor\n";

    // copy original's elements into m_ptr's underlying int array. We don't want to alter the original
    const std::span<const int> source{
            original.m_ptr.get(), original.size()};
    std::copy(std::begin(source), std::end(source), m_ptr.get());
}

// copy assignment operator: implemented with copy-and-wasp idiom
MyArray& MyArray::operator=(const MyArray& right) {
    std::cout << "MyArray copy assignment operator\n";
    MyArray temp{right};
    swap(*this, temp);
    return *this;
}

// move constructor: must receive a rvalue reference to a MyArray
MyArray::MyArray(MyArray &&original) noexcept
        : m_size{std::exchange(original.m_size, 0)},
          m_ptr{std::move(original.m_ptr)} {
    std::cout << "MyArray move constructor\n";
}

// move assignment operator
MyArray& MyArray::operator=(MyArray&& right) noexcept {
    std::cout << "MyArray move assignment operator\n";

    if (this != &right) {
        // move right's data into this MyArray
        m_size = std::exchange(right.m_size, 0);
        m_ptr = std::move(right.m_ptr);
    }

    return *this;
}

// destructor: This could be compiler-generated. We included it here so,
// we could output when each MyArray is destroyed.
MyArray::~MyArray() {
    std::cout << "MyArray destructor\n";
}

// return a string representation of a MyArray
std::string MyArray::toString() const {
    const std::span<const int> items{m_ptr.get(), m_size};
    std::ostringstream output;
    output << "{";

    // insert each item in the dynamic array into the ostringstream
    for (size_t count{0}; const auto& item : items) {
        ++count;
        output << item << (count < m_size ? ", " : "");
    }

    output << "}";
    return output.str();
}

// determine if two MyArrays are equal and
// return true, otherwise return false
bool MyArray::operator==(const MyArray& right) const noexcept {
    // compare corresponding elements of both MyArrays
    const std::span<const int> lhs{m_ptr.get(), m_size};
    const std::span<const int> rhs{right.m_ptr.get(), right.m_size};
    return std::equal(std::begin(lhs), std::end(lhs),
                      std::begin(rhs), std::end(rhs));
}

// overloaded subscript operator for non-const MyArrays;
// reference return creates a modifiable lvalue
int& MyArray::operator[](size_t index) {
    // check for index out-of-range error
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }

    return m_ptr[index]; // reference return
}

// overloaded subscript operator for const MyArrays
// const reference return creates a non-modifiable lvalue
const int& MyArray::operator[](size_t index) const {
    // check for subscript out-of-range error
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }

    return m_ptr[index]; // returns copy of this element
}

// preincrement every element, then return updated MyArray
MyArray& MyArray::operator++() {
    // use a span and for_each to increment every element
    const std::span<int> items{m_ptr.get(), m_size};
    std::for_each(std::begin(items), std::end(items),
                  [](auto& item){ ++item; });
    return *this;
}

// postincrement every element, and return copy of original MyArray
MyArray MyArray::operator++(int) {
    MyArray temp(*this);
    ++(*this);
    return temp;
}

// add value to every element, then return updated MyArray
MyArray &MyArray::operator+=(int value) {
    // use a span and for_each to increment very element
    const std::span<int> items{m_ptr.get(), m_size};
    std::for_each(std::begin(items), std::end(items),
                  [value](auto& item) { item += value; });
    return *this;
}

// overloaded input operator for class MyArray;
// inputs values for entire MyArray
std::istream& operator>>(std::istream& in, MyArray& a) {
    std::span<int> items{a.m_ptr.get(), a.m_size};

    for (auto &item: items) {
        in >> item;
    }

    return in;
}

// overloaded output operator for class MyArray
std::ostream& operator<<(std::ostream& out, const MyArray& a) {
    out << a.toString();
    return out;
}

// swap function used by copy assignment operator
void swap(MyArray &a, MyArray &b) noexcept {
    std::swap(a.m_size, b.m_size);
    a.m_ptr.swap(b.m_ptr); // using unique_ptr's swap function
}