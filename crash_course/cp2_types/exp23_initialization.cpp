//
// Created by andy- on 2021-10-31.
//

#include <cstdio>
#include <cstdint>

// Initializing class members
struct JohanVanDerSmut {
    bool gold = true;
    int year_of_smelting_accident{ 1970 };
    char key_location[8] = { "x-rated" };
};

struct PodStruct {
    uint64_t a;
    char b[265];
    bool c;
};

struct Taxonomist {
    Taxonomist() {
        printf("(no argument)\n");
    }
    Taxonomist(char x) {
        printf("char: %c\n", x);
    }
    Taxonomist(int x) {
        printf("int: %d\n", x);
    }
    Taxonomist(float x) {
        printf("float: %f\n", x);
    }
};

int main() {
    int a = 0;      // Initialized to 0
    int b{};        // Initialized to 0
    int c = {};     // Initialized to 0
    int d;          // Initialized to 0 (maybe), unreliable

    int e = 42;     // Initialized to 42
    int f{42};      // Initialized to 42
    int g = {42};   // Initialized to 42
    int h(42);      // Initialized to 42

    // Initializing PODs
    PodStruct initialized_pod1{};       // All fields zeroed
    PodStruct initialized_pod2 = {};    // All fields zeroed

    PodStruct initialized_pod3{42, "Hello"};    // Fields 1 & b set; c = 0
    PodStruct initialized_pod4{42, "Hello", true};   // All fields set

    // Initializing array
    int array_1[]{1, 2, 3};     // Array of length 3; 1, 2, 3
    int array_2[5]{};           // Array of length 5; 0, 0, 0, 0, 0
    int array_3[5]{1, 2, 3};    // Array of length 5; 1, 2, 3, 0, 0
    int array_4[5];             // Array of length 5; uninitialized values

    // Initializing fully featured class
    Taxonomist t1;
    Taxonomist t2{'c'};
    Taxonomist t3{65537};
    Taxonomist t4{6.02e23f};
    Taxonomist t5{'g'};
    Taxonomist t6 = {'1'};
    Taxonomist t7{};
    Taxonomist t8();

    // Narrowing Conversions
    float a1 = 1;
    float a2 = 2;
    int narrowed_result(a/b);   // Potentially nasty narrowing conversion
    int result{a/b};            // Compiler generates warning
}

