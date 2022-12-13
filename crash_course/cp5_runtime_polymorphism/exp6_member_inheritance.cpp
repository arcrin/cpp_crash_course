//
// Created by andy- on 2021-11-10.
//

#include <cstdio>

struct BaseClass {
    int the_answer() const { return 42; }

    const char *member = "gold";
private:
    const char *holistic_detective = "Dirk Gently";
};

struct DerivedClass: BaseClass {};

int main() {
    DerivedClass x;
    printf("The answer is %d\n", x.the_answer());
    printf("%s member\n", x.member);
    // following line would not compile. holistic_detective is a private member
    printf("%s's Holistic Detective Agency\n", x.holistic_detective);
}