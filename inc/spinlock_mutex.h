//
// Created by wangyz38535 on 2023/3/1.
//

#ifndef NODE_BOOKS_SPINLOCK_MUTEX_H
#define NODE_BOOKS_SPINLOCK_MUTEX_H

#include <atomic>

/*
 *  memory_order_acquire : 在这个load操作之前
 *
 *
 * */

class SpinLock {
public:
    SpinLock() : flags(ATOMIC_FLAG_INIT) {}

    void lock() {
        while (flag.test_and_set(std::memory_order_acquire));
    }

    void unlock() {
        flag.clear(std::memory_order_release);
    }


private:
    std::atomic_flag flag;
};



#endif //NODE_BOOKS_SPINLOCK_MUTEX_H
