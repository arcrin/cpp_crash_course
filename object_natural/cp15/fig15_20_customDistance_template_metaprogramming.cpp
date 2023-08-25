#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <ranges>
#include <type_traits>

template <std::input_iterator Iterator>
auto customDistance(Iterator begin, Iterator end) {
    if constexpr (std::is_base_of_v<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>) {
        std::cout << "Using random-access iterator\n";
        return end - begin;
    } else {
        std::ptrdiff_t distance{0};
        std::cout << "Using non-random-access iterator\n";
        for (Iterator iter{begin}; iter != end; ++iter) {
            ++distance;
        }
        return distance;
    }
}

int main() {
    const std::array ints1{1, 2, 3, 4, 5};
    const std::list ints2{1, 2, 3};

    auto result1{customDistance(ints1.begin(), ints1.end())};
    std::cout << "ints1 number of elements: " << result1 << "\n";
    auto result2{customDistance(ints2.begin(), ints2.end())};
    std::cout << "ints2 number of elements: " << result2 << "\n";
}