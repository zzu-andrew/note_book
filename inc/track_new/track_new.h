//
// Created by wangyz38535 on 2024/5/6.
//

#ifndef NODE_BOOKS_TRACK_NEW_H
#define NODE_BOOKS_TRACK_NEW_H


#include <new>       // for std::align_val_t
#include <cstdio>    // for printf()
#include <cstdlib>   // for malloc() and aligned_alloc()
#ifdef _MSC_VER
#include <malloc.h>  // for _aligned_malloc() and _aligned_free()
#endif

void* aligned_malloc(size_t size, size_t alignment) {
    void* raw_memory = nullptr;
    void* aligned_memory = nullptr;

    // 分配额外的空间用于对齐和存放原始指针
    const size_t space_for_alignment = alignment - 1 + sizeof(void*);
    raw_memory = malloc(size + space_for_alignment);

    if (!raw_memory) {
        return nullptr; // 分配失败
    }


    // 对齐调整
    uintptr_t ptr_value = reinterpret_cast<uintptr_t>(raw_memory);
    uintptr_t aligned_ptr_value = (ptr_value + alignment - 1) & ~(alignment - 1);

    // 保存原始指针以便后续释放
    aligned_memory = reinterpret_cast<void*>(aligned_ptr_value);
    *(reinterpret_cast<void**>(aligned_memory) - 1) = raw_memory;

    return aligned_memory;
}

void aligned_free(void* aligned_memory) {
    if (aligned_memory) {
        void* raw_memory = (*(reinterpret_cast<void**>(aligned_memory) - 1));
        free(raw_memory);
    }
}

// 实现对new的跟踪，这样实现了之后会覆盖原有的new
// 实现观察对new调用的观察
class TrackNew {
private:
    static int numMalloc;    // num malloc calls
    static size_t sumSize;   // bytes allocated so far
    static bool doTrace; // tracing enabled
    static bool inNew;   // don't track output inside new overloads
public:
    static void reset() {               // reset new/memory counters
        numMalloc = 0;
        sumSize = 0;
    }

    static void trace(bool b) {         // enable/disable tracing
        doTrace = b;
    }

    // implementation of tracked allocation:
    static void* allocate(std::size_t size, std::size_t align,
                          const char* call) {
        // track and trace the allocation:
        ++numMalloc;
        sumSize += size;
        void* p;
        if (align == 0) {
            p = aligned_malloc(size, 4);
        }
        else {
#ifdef _MSC_VER
            p = _aligned_malloc(size, align);     // Windows API
#else
            //p = std::aligned_alloc(align, size);  // C++17 API
            p = aligned_malloc(size, align);
#endif
        }
        if (doTrace) {
            // DON'T use std::cout here because it might allocate memory
            // while we are allocating memory (core dump at best)
            printf("#%d %s ", numMalloc, call);
            printf("(%zu bytes, ", size);
            if (align > 0) {
                printf("%zu-byte aligned) ", align);
            }
            else {
                printf("def-aligned) ");
            }
            printf("=> %p (total: %zu bytes)\n", (void*)p, sumSize);
        }
        return p;
    }

    static void status() {              // print current state
        printf("%d allocations for %zu bytes\n", numMalloc, sumSize);
    }
};

int TrackNew::numMalloc = 0;    // num malloc calls
size_t TrackNew::sumSize = 0;   // bytes allocated so far
bool TrackNew::doTrace = false; // tracing enabled
bool TrackNew::inNew = false;   // don't track output inside new overloads

[[nodiscard]]
void* operator new (std::size_t size) {
    return TrackNew::allocate(size, 0, "::new");
}

[[nodiscard]]
void* operator new (std::size_t size, size_t align) {
    return TrackNew::allocate(size, static_cast<size_t>(align),
                              "::new aligned");
}

[[nodiscard]]
void* operator new[] (std::size_t size) {
    return TrackNew::allocate(size, 0, "::new[]");
}

[[nodiscard]]
void* operator new[] (std::size_t size, size_t align) {
    return TrackNew::allocate(size, static_cast<size_t>(align),
                              "::new[] aligned");
}

// ensure deallocations match:
void operator delete (void* p) noexcept {
    aligned_free(p);
}
void operator delete (void* p, std::size_t) noexcept {
    aligned_free(p);
}

void operator delete (void* p, std::size_t,
                      size_t align) noexcept {
    ::operator delete(p, align);
}


#endif //NODE_BOOKS_TRACK_NEW_H
