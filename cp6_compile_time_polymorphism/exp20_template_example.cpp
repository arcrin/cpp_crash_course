//
// Created by andy- on 2021-11-14.
//

#include <iostream>
#include <string>

template <typename T>
void Print(T value) {
    std::cout << value << std::endl;
}

//void Print(int value) {
//    std::cout << value << std::endl;
//}
//
//void Print(std::string value) {
//    std::cout << value << std::endl;
//}

template<typename T, int size>
class Array
{
private:
    T m_array[size];
public:
    Array(int* values){
        m_array = values;
    }
    int GetSize() const { return size; }
};

int main() {
//    Print(1);
//    Print("Wen");
    int temp[3] = {1, 2, 3};
    Array<int, 3> array{temp};
    Print(array.GetSize());
}