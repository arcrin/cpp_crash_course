//
// Created by wbai on 11/23/2021.
//

#include <cstdio>
#include <cstdint>


struct CountIf {
    CountIf(char x) : x{x} {}
    size_t operator()(const char* str) const {
        size_t index{}, result{};
        while (str[index]) {
            if (str[index] == x) result++;
            index++;
        }
        return result;
    }
private:
    const char x;
};

int main() {
    CountIf s_counter{'s'};
    auto sally = s_counter("Sally sells seashells by the seashore.");
    printf("Sally: %zu\n", sally);
    auto sailor = s_counter("Sailor went to sea to see what he could see.");
    printf("Sailor: %zu\n", sailor);
    auto buffalo = CountIf{ 'f' }("Buffalo buffalo Buffalo buffalo "
                                  "buffalo buffalo Buffalo buffalo.");
    printf("Buffalo: %zu\n", buffalo);
}

/*
 * You can employ function objects as partial applications
 */

size_t count_if(char x, const char* str) {
    size_t index{}, result{};
    while (str[index]) {
    if (str[index] == x) result++;
    index++;
    }
    return result;
}
/*
 * above function is the same as Countif function call operator, with an extra argument x
 */
