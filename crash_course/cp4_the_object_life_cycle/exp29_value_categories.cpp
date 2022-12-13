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
 * Moving can be dangerous. If you accidentally use moved-from a, you'd invite disaster. The class invariants of
 * SimpleString aren't satisfied when is moved from.
 *
 * Fortunately, the compiler has built-in safeguards: lvalues and rvalues
 */

int main() {
    SimpleString a{50};
    SimpleStringOwner b{a}; // a is an lvalue
    SimpleStringOwner c{SimpleString{50}}; // SimpleString{50} is an rvalue
}

/*
 * The etymology of these terms is right value and left value, referring to where each appears with respect to the equal
 * sign in construction.
 *
 * These terms are not totally accurate because you can have an lvalue on the right side of an equal sign (as in copy
 * assignment, for example)
 */