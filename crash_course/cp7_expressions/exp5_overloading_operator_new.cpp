//
// Created by andy- on 2021-11-15.
//

/*
 * Recall from chapter 4 that you allocate objects with dynamic storage duration using operator new. By default,
 * operator new will allocate memory on the free sore to make space for your dynamic objects. The free store, also
 * known as the heap, is an implementation-defined storage location. On desktop operating systems, the kernel usually
 * manages the free store (see the HeapAlloc on Windows and malloc on Linux and macOS) and is generally vast.
 */

/*
 * Free Store Availability
 *
 * In some environments, like Windows kernel or embedded systems, there is no free store available to you by default.
 * In other settings, such as game development or high-frequency trading, free store allocations simply involve too
 * much latency, because you have delegated its management to the operating system.
 *
 * You could try to avoid using the free store entirely, but this is severely limiting. One major limitation this would
 * introduce is to preclude the use of stdlib containers, which after reading part II you will agree is a major loss.
 * Rather than settling for these sever restrictions, you can overload the free store operations and take control over
 * allocations. You do this by overloading operator "new".
 */

/*
 * The <new> Header
 * In environments that support free store operations, the <new> header contains the following four operators:
 *  1. void* operator new(size_t)
 *  2. void operator delete(void*)
 *  3. void* operator new[](size_t)
 *  4. void operator delete[](void*)
 *
 *  Notice that the return type of operator new is void*. The free store operators deal in raw, uninitialized memory.
 */

/*
 * Free store management is a surprisingly complicated task. One of the major issues is memory fragmentation. Over time,
 * large numbers of memory allocations and releases can leave free blocks of memory scattered throughout the region
 * dedicated for the free store. It's possible to get into situations where there is plenty of free memory, but it is
 * scattered across allocated memory. When this happens, requests for large memory will fail, even thought there is
 * technically enough free memory to provide to the requester.
 */

/*
 * Buckets
 *
 * One approach is to chop allocated memory into so-called buckets of a fixed size. When you request memory, the
 * environment allocates a whole bucket, even if you didn't request all the memory. For example, Windows provides two
 * functions for allocating dynamic memory: VirtualAllocEx and HeapAlloc.
 *
 * The VirtualAllocEx function is low level, which allows you to provide many options, such as which process to allocate
 * memory into, the preferred memory address, the requested size, and permissions, like whether the memory should be
 * readable, writable, and executable. This function will never allocate fewer than 4096 bytes (a so-called page).
 *
 * On the other hand, HeapAlloc is higher-level function that hands out less than a page of memory when it can;
 * otherwise, it will invoke VirtualAllocEx on your behalf. With Visual Studio compiler, "new" will call HeapAlloc by
 * default.
 *
 * This arrangement prevents memory fragmentation in exchange for some overhead associated with rounding up allocations
 * to bucket size. Modern operating systems like Windows will have fairly complex schemes for allocating memory of
 * different sizes. You don't see any of this complexity unless you want to take control.
 */

/*
 * Taking control of the free store
 */

#include <cstddef>
#include <new>
#include <cstdio>


struct Bucket {
    const static size_t data_size{4096};
    std::byte data[data_size];
};

struct Heap {
    void* allocate(size_t bytes){
        if(bytes > Bucket::data_size) throw std::bad_alloc{};
        for (size_t i{}; i < n_heap_buckets; i++) {
            if(!bucket_used[i]) {
                bucket_used[i] = true;
                return buckets[i].data;
            }
        }
        throw std::bad_alloc{};
    }

    void free(void *p) {
        for (size_t i{}; i < n_heap_buckets; i++) {
            if (buckets[i].data == p) {
                bucket_used[i] = false;
                return;
            }
        }
    }
    static const size_t n_heap_buckets{10};
    Bucket buckets[n_heap_buckets];
    bool bucket_used[n_heap_buckets];
};

Heap heap;

void* operator new(size_t n_bytes) {
//    printf("New operator overload\n");
    return heap.allocate(n_bytes);
}

void operator delete(void* p) noexcept{
    printf("Delete operator overload\n");
    return heap.free(p);
}

int main() {
    printf("Buckets:    %p\n", heap.buckets);
    auto breakfast = new unsigned int{0xC0FFEE};
    auto dinner = new unsigned int{0xDEADBEEF};
    printf("Breakfast:  %p 0x%x\n", breakfast, *breakfast);
    printf("Dinner:     %p 0x%x\n", dinner, *dinner);
    delete breakfast;
    delete dinner;
    try {
        while (true) {
            new char;
            printf("Allocated a char.\n");
        }
    } catch (const std::bad_alloc&) {
        printf("std::bad_alloc caught.\n");
    }
}