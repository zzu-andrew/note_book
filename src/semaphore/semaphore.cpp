//
// Created by wangyz38535 on 2024/4/23.
//

#include <atomic>
#include <iostream>
#include <mutex>
#include <condition_variable>

/**
 * @brief A simple Semaphore to limit request concurrency.
 */
class Semaphore {
public:
    explicit Semaphore(std::size_t permits) : permits_(permits) {
    }

    /**
     * @brief Acquire a permit.
     */
    void acquire() {
        while (true) {
            std::unique_lock<std::mutex> lk(mtx_);
            if (permits_ > 0) {
                permits_--;
                return;
            }
            cv_.wait(lk, [this]() { return permits_ > 0; });
        }
    }

    /**
     * @brief Release the permit back to semaphore.
     */
    void release() {
        std::unique_lock<std::mutex> lk(mtx_);
        permits_++;
        if (1 == permits_) {
            cv_.notify_one();
        }
    }

private:
    std::size_t permits_{0};
    std::mutex mtx_;
    std::condition_variable cv_;
};


int GetData(std::unique_lock<std::mutex> &lk) {




    return 0;
}


// 简单实现一个同时只有指定人数能获取的信号量，permits_为指定多少人能同时获取，获取的人数不能超过这个数，否则等待

int main(int argc, char *argv[]) {

    std::mutex mux;

    std::unique_lock<std::mutex> lock(mux);
    GetData(lock);



    return 0;
}


