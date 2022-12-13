//
// Created by andy- on 2021-11-06.
//

/*
 * For fundamental and POD types, the story is straightforward. Copying these types is member-wise, which means each
 * member gets copied into its corresponding destination. This is effectively a bitwise copy from one memory address
 * to another.
 */

/*
 * Fully featured classes require some more thought. The default copy semantics for fully featured classes is also
 * the member-wise copy, and this can be extremely dangerous. Take SimpleString class, a member-wise copy on buffer[]
 * would create another SimpleString object points to the same buffer[]. This would cause problems during appending and
 * destruction (double free problem).
 */

/*
 * You can avoid this dumpster fire by taking control of copy semantics. You can specify copy constructors and
 * copy assignment operators.
 */

/*
 * Copy Constructors
 */

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

int main() {
    SimpleString a{50};
    a.append_line("We apologize for the");
    SimpleString a_copy{a};
    a.append_line("inconvenience.");
    a_copy.append_line("incontinence.");
    a.print("a");
    a_copy.print("a_copy");
}