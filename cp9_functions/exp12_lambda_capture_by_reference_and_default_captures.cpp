//
// Created by wbai on 11/23/2021.
//


#include <cstdio>
#include <cstdint>

int main() {
    char to_count{'s'};
    size_t tally{};
    // default capture allows you to skip the name of the captures, try not to use default capture
    auto s_counter = [&, to_count](const char* str) { // need mutable if all are captured by value
        size_t index{}, result{};
        while(str[index]) {
            if(str[index] == to_count) result++;
            index++;
        }
        tally += result;
        return result;
    };
    printf("Tally: %zu\n", tally);
    auto sally = s_counter("Sally sells seashells by the seashore.");
    printf("Sally: %zu\n", sally);
    printf("Tally: %zu\n", tally);
    auto sailor = s_counter("Sailor went to sea to see what he could see.");
    printf("Sailor: %zu\n", sailor);
    printf("Tally: %zu\n", tally);
}