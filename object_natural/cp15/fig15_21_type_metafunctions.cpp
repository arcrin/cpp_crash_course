// fig15_21
// Adding and removing type attributes with type meta-functions
#include <fmt/format.h>
#include <iostream>
#include <type_traits>

// add const to a type T
template <typename T>
struct my_add_const {
    using type = const T;
};

// general case: no pointer in type, so set nested type variable to T
template <typename T>
struct my_remove_ptr {
    using type = T;
};

// partial template specialization: T is a pointer type, so remove *
template <typename T>
struct my_remove_ptr <T*> { // partial template specialization, include the parameter in angle brackets
    using type = T;
};

int main() {
    std::cout << fmt::format("{}\n{}{}\n{}{}\n\n",
                             "ADD CONST TO A TYPE VIA A CUSTOM TYPE METAFUNCTION",
                             "std::is_same_v<const int, my_add_const<int>::type: ",
                             std::is_same_v<const int, my_add_const<int>::type>, // add const qualifier to the int type, then check
                             "std::is_same_v<int* const, my_add_const<int*>::type>: ",
                             std::is_same_v<int* const, my_add_const<int*>::type>); // add const qualifier to int* (pointer), then check

    std::cout << fmt::format("{}\n{}{}\n{}{}\n{}{}\n\n",
                             "REMOVE POINTER FROM TYPES VIA A CUSTOM TYPE METAFUNCTION",
                             "std::is_same_v<int, my_remove_ptr<int>::type>: ",
                             std::is_same_v<int, my_remove_ptr<int>::type>,
                             "std::is_same_v<int, my_remove_ptr<int*>::type>: ",
                             std::is_same_v<int, my_remove_ptr<int*>::type>, // remove the pointer qualification
                             "std::is_same_v<int, std::remove_pointer_t<int*>: ",
                             std::is_same_v<int, std::remove_pointer_t<int*>>);


    std::cout << fmt::format("{}\n{}{}\n{}{}\n\n",
                             "ADD REFERENCE TO TYPES USING STANDARD TYPE TRAITS",
                             "std::is_same_v<int&, std::add_lvalue_reference<int>::type>: ",
                             std::is_same_v<int &, std::add_rvalue_reference<int>::type>,
                             "std::is_same_v<int&&, std::add_rvalue_reference<int>::type>: ",
                             std::is_same_v<int &&, std::add_rvalue_reference<int>::type>);



    std::cout << fmt::format("{}\n{}{}\n{}{}\n\n",
                             "REMOVE REMOVE REFERENCES FROM TYPES USING STANDARD TYPE TRAITS",
                             "std::is_same_v<int, std::remove_reference<int>::type>: ",
                             std::is_same_v<int, std::remove_reference<int>::type>,
                             "std::is_same_v<int, std::remove_reference<int&>::type>: ",
                             std::is_same_v<int, std::remove_reference<int&>::type>,
                             "std::is_same_v<int, std::remove_reference<int&&>::type>: ",
                             std::is_same_v<int, std::remove_reference<int&&>::type>);
}