//
// Created by wbai on 11/13/2021.
//

#include <cstdio>
#include <utility>

/*
 * A unique pointer is an RAII wrapper around a free-store-allocated object. As the name suggests, the unique pointer
 * has a single owner at a time, so when a unique pointer's lifetime ends, the pointed-to object gets destructed.
 * The underlying object's type in unique pointers doesn't matter, making them a prime candidate for a template class.
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

struct Tracer {
    Tracer(const char* name) : name{name} {
        printf("%s constructed.\n", name);
    }
    ~Tracer() {
        printf("%s destructed.\n", name);
    }
private:
    const char *const name;
};

void consumer(SimpleUniquePointer<Tracer> consumer_ptr) {
    printf("(cons) consumer_ptr: 0x%p\n", consumer_ptr.get());
}

int main() {
    auto ptr_a = SimpleUniquePointer(new Tracer{"ptr_a"});
    printf("(main) ptr_a: 0x%p\n", ptr_a.get());
    consumer(std::move(ptr_a));
    printf("(main) ptr_a: 0x%p\n", ptr_a.get());
}