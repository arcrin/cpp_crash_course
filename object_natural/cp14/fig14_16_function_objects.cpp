#include <array>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

// binary function returns the sum of its first argument total
// and the square of its second argument value
int sumSquares(int total, int value) {
    return total + value * value;
}

// class SumSquaresClass defines overloaded operator()
// that returns the sum of its first argument total
// and the square of its second argument value
class SumSquaresClass {
public:
    // add square of value to total and return result
    int operator()(int total, int value) {
        return total + value * value;
    }
};

int main() {
    std::array integers{1, 2, 3, 4};
    std::ostream_iterator<int> output{std::cout, " "};

    std::cout << "array integers contains: ";
    std::ranges::copy(integers, output);

    // calculate sum of squares of elements of array integers
    // using binary function sumSquares
    int result{std::accumulate(integers.cbegin(), integers.cend(), 0, sumSquares)};

    std::cout << "\n\nSum of squares\n" << "via binary function sumSquares: " << result;

    // calculate sum of square of elements of array integers
    // using binary function object
    result = std::accumulate(integers.cbegin(), integers.cend(), 0, SumSquaresClass{});
    std::cout << "\nvia a SumSquaresClass function object: " << result;

    // calculate sum of squares array
    result = std::accumulate(integers.cbegin(), integers.cend(), 0, [](auto total, auto value){
        return total + value * value;
    });
    std::cout << "\nvia a lambda: " << result << "\n";
}