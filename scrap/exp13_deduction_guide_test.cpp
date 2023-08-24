//
// Created by wbai on 8/22/2023.
//
#include <memory>
#include <iostream>
template <typename T, size_t SIZE>
struct MyArray {
    T m_data[SIZE];
};

template<typename T, std::same_as<T> ... Us>
MyArray(T first, Us... rest) -> MyArray<T, 1 + sizeof...(Us)>;

int main() {
    MyArray ints{1, 2, 3, 4, 5, 6};
    int m_dataSize = sizeof(ints.m_data) / sizeof(ints.m_data[0]);
    std::cout << "test\n";
    for (int i{0}; i < m_dataSize; ++i) {
        std::cout << ints.m_data[i] << " ";
    }
}