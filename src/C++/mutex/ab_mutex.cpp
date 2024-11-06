//
// Created by wangyz38535 on 2024/11/6.
//

#include <iostream>
#include <vector>
#include <queue>
#include <condition_variable>
#include <functional>
#include <thread>
#include <thread/thread_pool_simple.h>

using namespace std;





int main() {
    try {
        // 启动三个线程
        std::mutex lock;
        ThreadPool pool(3);
        for (int i = 0; i < 8; ++i) {
            pool.enqueue([&lock](const std::atomic_bool& bStop) {
                std::cout << "Require lock " << std::endl;
                lock.lock();
                std::cout << "Locked" << std::endl;
                while (!bStop) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            });
        }
        while (true) {
            std::vector<bool> threads_executing = pool.get_threads_executing();
            std::cout << "Threads executing: ";
            for (bool executing : threads_executing) {
                std::cout << (executing ? "T" : "F") << " ";
            }
            std::cout << std::endl;
            // 没有任何线程在执行
            if (pool.get_threads_executing().empty()) {
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        pool.wait();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
