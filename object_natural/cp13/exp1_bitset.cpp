#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> myBitset(42);
    std::cout << "Original bitset: " << myBitset << std::endl;

    myBitset.set();
    std::cout << "After set(): " << myBitset << std::endl;

    myBitset.reset();
    std::cout << "After reset(): " << myBitset << std::endl;

    myBitset.flip();
    std::cout << "After flip(): " << myBitset << std::endl;

    myBitset.reset(0);
    std::cout << "After flip(0): " << myBitset << std::endl;

    std::cout << myBitset.to_ulong();

}