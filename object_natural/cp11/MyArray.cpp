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

// MyArray constructor to create a MyArray of size elements containing 0
MyArray::MyArray(size_t size)
: m_size{size}, m_ptr{std::make_unique<int[]>(size)}, m_id{m_ptr.get()}{
    std::cout << fmt::format("MyArray(size_t size) created: {}\n", static_cast<void*>(m_id));

}

// MyArray copy constructor
MyArray::MyArray(const MyArray &original)
        : m_size{original.m_size}, m_ptr{std::make_unique<int[]>(original.size())}, m_id{m_ptr.get()} {
    std::span<int> source(original.m_ptr.get(), original.m_size);
    std::copy(std::begin(source), std::end(source), m_ptr.get());
}

MyArray::~MyArray() {
    std::cout << fmt::format("MyArray destroyed {}\n", static_cast<void*>(m_id));
}

std::string MyArray::toString() const{
    std::ostringstream out;
    std::span<int> items(m_ptr.get(), m_size);
    out << "{";
    for (size_t count{0}; auto &item: items) {
        ++count;
        out << item << (count < m_size ? ", " : "");
    }
    out << "}";
    return out.str();
}

std::istream &operator>>(std::istream &in, MyArray &a){
    std::span<int> items(a.m_ptr.get(), a.m_size);

    for (auto &item: items) {
        in >> item;
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const MyArray &a) {
    out << a.toString();
    return out;
}

bool MyArray::operator==(const MyArray &right) const noexcept {
    std::span<const int> lhs{m_ptr.get(), size()};
    std::span<const int> rhs{right.m_ptr.get(), right.m_size};
    return std::equal(std::begin(lhs), std::end(lhs),
               std::begin(rhs), std::end(rhs)); // std::equal can not take unique_ptr as argument
}
