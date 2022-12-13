//
// Created by andy- on 2021-11-06.
//

#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
    SimpleString(size_t max_size):max_size{max_size}, length{} {
        printf("Created!\n");
        if (max_size == 0) {
            throw std::runtime_error{"Max size must be at least 1."};
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }

    SimpleString(const char* new_string) // C++ string literals are arrays of char, which means you can't
    // legally modify them. If you want to safely assign a string literal to a pointer (which involves an implicit
    // array-to-pointer conversion), you need to declare the target pointer as const char*, not just as char*
        :max_size{strlen(new_string) + 2}, length{strlen(new_string)}
    { // Need to initialize max_length and length; otherwise they will take on some random huge value that causes
        // segmentation fault
        printf("Constructed with string literal\n");
        buffer = new char[max_size];
        buffer[0] = 0;
        std::strncpy(buffer, new_string, strlen(new_string));
        buffer[length++] = '\n';
        buffer[length] = 0;
    }

    SimpleString(const SimpleString &other)
            :max_size{other.max_size},
             buffer{new char[other.max_size]},
             length{other.length}{
        printf("Copied!\n");
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
        printf("Moved!\n");
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

    SimpleString& operator=(SimpleString&& other) noexcept {
        if (this == &other) return *this;
        delete[] buffer;
        buffer = other.buffer;
        length = other.length;
        max_size = other.max_size;
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;
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
        printf("SimpleString destructor\n");
        delete[] buffer; // resource acquisition is initialization (RAII);
        // constructor acquires, destructor releases(CADRe)
    }

private:
    size_t max_size;
    char *buffer{};
    size_t length;
};

struct SimpleStringOwner {
//    explicit SimpleStringOwner(const char* x)
//            :string{x} {
//        printf("Owner given a string literal\n");
//    }

    explicit SimpleStringOwner(SimpleString& new_string)
        :string{new_string}{
        printf("Owner given a SimpleString lvalue reference\n");
    }

    explicit SimpleStringOwner( SimpleString&& x)
        :string{std::move(x)} {
        printf("Owner given a SimpleString rvalue reference\n");
    }

    ~SimpleStringOwner() {
        printf("SimpleStringOwner destructor\n");
    }

    void print(const char* tag) {
        string.print(tag);
    }
private:
    SimpleString string;
};


int main() {
//    SimpleStringOwner owner_a{"Test string literal"};
//    owner_a.print("a");
//    SimpleString b{"Test string lvalue"};
//    SimpleStringOwner owner_b{b};
//    owner_b.print("b");
    SimpleStringOwner owner_c{"Test string rvalue"};
    owner_c.print("c");
}