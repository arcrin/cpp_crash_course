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

    /*
     * Move constructors look like copy constructors except they take rvalue references instead of lvalue references.
     *
     * The move constructor is designed to not throw an exception, so you mark it noexcept. Your preference should be
     * to use noexcept move constructors; often compiler cannot use exception-throwing move constructors and will
     * use copy constructors instead. Compilers prefer slow, correct code instead of fast, incorrect code.
     */
    SimpleString(SimpleString&& other) noexcept
        : max_size{other.max_size},
        buffer{other.buffer},
        length{other.length} {
        other.length = 0;   // zero out the fields of "other".
        other.buffer = nullptr; //These steps are important: it puts "other" in a "moved-from" state.
        other.max_size = 0; // (Consider what would happen upon the destruction of "other" had
                            // you not cleared its members.)
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

