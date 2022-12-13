//
// Created by andy- on 2021-11-06.
//

#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
    SimpleString(size_t max_size):max_size{max_size}, length{} {
        if (max_size == 0) {
            throw std::runtime_error{"Max size must be at least 1."};
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }

    SimpleString(const SimpleString &other)
            :max_size{other.max_size},
             buffer{new char[other.max_size]},
             length{other.length}{
        std::strncpy(buffer, other.buffer, max_size);
    }

    SimpleString& operator=(const SimpleString& other) {
        if (this == &other) return *this;
        const auto new_buffer = new char[other.max_size];
        delete[] buffer;
        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;
        std::strncpy(buffer, other.buffer, max_size);
        return *this;
    }

    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

    bool append_line(const char* x) {
        const auto x_len = strlen(x);
        if (x_len + length + 2 > max_size) return false;
        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
    ~SimpleString() {
        delete[] buffer; // resource acquisition is initialization (RAII);
        // constructor acquires, destructor releases(CADRe)
    }

private:
    size_t max_size;
    char *buffer;
    size_t length;
};

struct SimpleStringOwner {
    explicit SimpleStringOwner(const char* x)
            :string{10} {
        if (!string.append_line(x)) {
            throw std::runtime_error{"Not enough memory!"};
        }
        string.print("Constructed");
    }

    explicit SimpleStringOwner(const SimpleString& my_string): string{my_string} {}

    ~SimpleStringOwner() {
        string.print("Abort to destroy");
    }
private:
    SimpleString string;
};

/*
 * Copying can be quite time-consuming at runtime when a large amount of data is involved. Often, you just want to
 * transfer the ownership of resources from one object to another. You could make a copy and destroy the original,
 * but this is often inefficient. Instead, you can "move"
 *
 * "Move" semantics is move's corollay to copy semantics, and it requires that after an object y is moved into an object
 * x, x is equivalent to the former value of y. After the move, y is in special state called the moved-from state.
 * You can perform only two operations on moved-from objects: (re)assign them or destruct them. Note that moving an
 * object y into an object x isn't just a renaming: these are separate objects with separate storage and potentially
 * separate lifetimes.
 *
 * Similar to how you specify copying behavior, you specify how objects move with move constructors and move assignment
 * operators
 */


/*
 * Copying can be wasteful
 */

void own_a_string() {
    SimpleString a{50};
    a.append_line("We apologize for the");
    a.append_line("inconvenience.");
    SimpleStringOwner b{a}; // this is wasteful, if a is never used again, a is destructible
}