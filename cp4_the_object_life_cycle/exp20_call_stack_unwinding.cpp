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
//        printf("%c", buffer[0]);
    }

    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

    bool append_line(const char* x) {
        const auto x_len = strlen(x);
//        printf("%d\n", x_len);
//        printf("%c\n", x[x_len]);
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
    SimpleStringOwner(const char* x)
            :string{10} {
        if (!string.append_line(x)) {
            throw std::runtime_error{"Not enough memory!"};
        }
        string.print("Constructed");
    }
    ~SimpleStringOwner() {
        /*
         * the member string is still valid at this point because member
         * destructors are called after the enclosing object's destructor
         *
         * All members are destructed after the object's destructor is
         * invoked
         */
        string.print("Abort to destroy");
    }
private:
    SimpleString string;
};


void fn_c() {
    SimpleStringOwner c{"cccccccccc"}; // exception heppens here
}

void fn_b() {
    SimpleStringOwner b{"b"};
    fn_c();
}

int main() {
    try {
        SimpleStringOwner a{"a"};
        fn_b();
        SimpleStringOwner d{"d"};
    } catch (const std::exception& e) {
        printf("Exception: %s\n", e.what());
    }
}