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

void dont_do_this() {
    SimpleString a{50};
    a.append_line("We apologize for the");
    SimpleString b{50};
    b.append_line("Last message");
    b = a; // b already have a value. You must clean up b's resources before copying a
    a.print("a");
    b.print("b");
}

int main() {
//    dont_do_this();
    SimpleString a{50};
    a.append_line("We apologize for the");
    SimpleString b{50};
    b.append_line("Last message");
    a.print("a");
    b.print("b");
    b = a;
    a.print("a");
    b.print("b");
}