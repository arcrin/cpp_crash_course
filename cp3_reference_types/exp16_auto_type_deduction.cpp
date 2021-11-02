//
// Created by wbai on 11/2/2021.
//

/*
 * Initialization with auto
 */
auto the_answer{42};                // int
auto foot{12L};                     // long
auto rootbeer{5.0F};                // float
auto cheeseburgerA{10.0};           // double
auto politifact_claims{false};      // bool
auto cheese{"string"};              // char[7]

/*
 * auto and reference types
 */
auto year{2019};                    // int
auto &year_ref = year;              // int&
const auto &year_cref = year;       // const int&
auto *year_ptr = &year;             // int*
const auto *year_cptr = &year;      // const int*

/*
 * auto and code refactoring
 */

struct Dwarf {
    // TODO: fill
};

Dwarf dwarves[13];

struct Contract {
    void add(const Dwarf &);
};

void form_company(Contract &contract) {
    for (const auto& dwarf: dwarves) {
        contract.add(dwarf);
    }
}