//
// Created by wbai on 8/2/2023.
#pragma once
#include <initializer_list>
#include <iostream>
#include <memory>

class MyArray final {
    //overloaded stream extraction operator
    friend std::istream &operator>>(std::istream &in, MyArray &a);

    // used by copy assignment operator to implement copy-and-swap idiom
    friend void swap(MyArray &a, MyArray &b) noexcept;

public:
    explicit MyArray(size_t size); // construct a MyArray of size elements

    // construct a MyArray with a braced-initializer list of ints
    MyArray(std::initializer_list<int> list);

    MyArray(const MyArray &original); // copy constructor
    MyArray &operator=(const MyArray& right); // copy assignment operator

    MyArray(MyArray&& original) noexcept; // move constructor
    MyArray& operator=(MyArray&& right) noexcept; // move assignment

    ~MyArray(); // destructor

    [[nodiscard]] size_t size() const noexcept { return m_size; }
    std::string toString() const; // create string representation

    // equality operator
    bool operator==(const MyArray &right) const noexcept;

    // subscript operator for non-const objects returns modifiable lvalue
    int &operator[](size_t index);

    // subscript operator for const objects returns non-modifiable lvalue
    const int &operator[](size_t index) const;

    // convert MyArray to a bool value: true if non-empty; false if empty
    explicit operator bool() const noexcept { return size() != 0; }

    // preincrement every element, then return updated MyArray
    MyArray &operator++();

    // postincrement every element, and return copy of original MyArray
    MyArray operator++(int);

    // add value to every element, then return updated MyArray
    MyArray &operator+=(int value);
private:
    size_t m_size{0}; // pointer-based array size
    std::unique_ptr<int[]> m_ptr; // smart pointer to integer array
};

// overload operator << is not a friend, does not access private data
std::ostream& operator<<(std::ostream& out, const MyArray& a);

