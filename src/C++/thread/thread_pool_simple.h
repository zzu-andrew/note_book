//
// Created by wangyz38535 on 2023/7/7.
//

#ifndef NODE_BOOKS_THREAD_POOL_SIMPLE_H
#define NODE_BOOKS_THREAD_POOL_SIMPLE_H

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>
#include <chrono>
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool(size_t numThreads = std::thread::hardware_concurrency()) :
            stop(false), num_idle_threads(0), num_threads_executing(0) {
        if (numThreads == 0) {
            throw std::invalid_argument("Invalid number of threads.");
        }
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back(
                    [this] {
                        for (;;) {
                            std::function<void()> task;
                            {
                                std::unique_lock<std::mutex> lock(this->queue_mutex);
                                this->condition.wait(lock,
                                                     [this] { return this->stop || !this->tasks.empty(); });
                                if (this->stop && this->tasks.empty())
                                    return;
                                if (this->tasks.empty()) {
                                    ++this->num_idle_threads;
                                    this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
                                    --this->num_idle_threads;
                                }
                                if (!this->tasks.empty()) {
                                    task = std::move(this->tasks.front());
                                    this->tasks.pop();
                                    ++this->num_threads_executing;
                                }
                            }
                            if (task) {
                                task();
                                --this->num_threads_executing;
                            }
                        }
                    }
            );
        }
    }

    template<class F>
    void enqueue(F&& f) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.emplace(std::forward<F>(f));
        }
        condition.notify_one();
    }

    void wait() {
        std::unique_lock<std::mutex> lock(queue_mutex);
        condition.wait(lock, [this] { return this->tasks.empty() && this->num_idle_threads == workers.size(); });
    }

    std::vector<bool> get_threads_executing() const {
        std::vector<bool> result(workers.size());
        for (size_t i = 0; i < workers.size(); ++i) {
            result[i] = (i < num_threads_executing);
        }
        return result;
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread& worker : workers)
            worker.join();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    std::atomic_bool stop;
    std::atomic_size_t num_idle_threads;
    std::atomic_size_t num_threads_executing;
};


void task(int i) {
    std::cout << "Thread " << std::this_thread::get_id() << ": Task " << i << " is running." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << std::this_thread::get_id() << ": Task " << i << " is done." << std::endl;
}

//int main() {
//    try {
//        ThreadPool pool;
//        for (int i = 0; i < 8; ++i) {
//            pool.enqueue([i] { task(i); });
//        }
//        while (true) {
//            std::vector<bool> threads_executing = pool.get_threads_executing();
//            std::cout << "Threads executing: ";
//            for (bool executing : threads_executing) {
//                std::cout << (executing ? "T" : "F") << " ";
//            }
//            std::cout << std::endl;
//            if (pool.get_threads_executing().empty()) {
//                break;
//            }
//            std::this_thread::sleep_for(std::chrono::milliseconds(500));
//        }
//        pool.wait();
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }
//    return 0;
//}



#endif //NODE_BOOKS_THREAD_POOL_SIMPLE_H
