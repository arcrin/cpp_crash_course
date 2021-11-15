//
// Created by andy- on 2021-11-14.
//

#include <cstdio>

/*
 * Sometimes, templates must take in an unknown number of arguments. The compiler knows these arguments at template
 * instantiation, but you want to avoid having to write many templates each for different numbers of arguments. This is
 * the reason for variadic templates. Variadic templates take a variable number of arguments.
 */

template <typename T>
struct SimpleUniquePointer {
    SimpleUniquePointer() = default; // the default constructor will set the private member T* pointer to nullptr
    SimpleUniquePointer(T* pointer)
            : pointer{pointer} {
    }
    ~SimpleUniquePointer() {
        if(pointer) delete pointer;
    }

    SimpleUniquePointer(const SimpleUniquePointer &) = delete;

    SimpleUniquePointer &operator=(const SimpleUniquePointer &) = delete;
    SimpleUniquePointer(SimpleUniquePointer&& other) noexcept
            : pointer{other.pointer} {
        printf("simple unique pointer move.\n");
        other.pointer = nullptr;
    }
    SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
        if(pointer) delete pointer;
        pointer = other.pointer;
        other.pointer = nullptr;
        return *this;
    }
    T* get() {
        return pointer;
    }
private:
    T *pointer;
};

template<typename T, typename... Arguments>
SimpleUniquePointer<T> make_simple_unique(Arguments... arguments) {
    return SimpleUniquePointer<T>{new T{arguments...}};
}