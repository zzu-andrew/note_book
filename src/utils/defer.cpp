//
// Created by wangyz38535 on 2024/4/23.
//


#include <atomic>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <set>
#include <map>

class LambdaDefer {
public:
    explicit LambdaDefer(std::function<int32_t()>&& func) : m_func(func) {}

    ~LambdaDefer() {
        if (m_func) {
            m_func();
        }
    }

    void SetNoDefer() {
        m_func = nullptr;
    }

private:
    std::function<int32_t()> m_func;
};




class LambdaDeferTuple {
public:
    LambdaDeferTuple() : m_funcIndex(0), m_funcs{} {}

    ~LambdaDeferTuple() {
        for (const auto& pair : m_funcs) {
            if (pair.second) {
                pair.second();
            }
        }
    }

    uint32_t PushFunction(std::function<uint32_t()>&& func) {
        auto index = m_funcIndex.fetch_add(1);
        m_funcs.insert(std::make_pair(index, func));
        return index;
    }

    void PopFunction(uint32_t index) {
        m_funcs.erase(index);
    }

    void SetNoDefer() {
        m_funcs.clear();
    }

private:
    std::atomic<uint32_t> m_funcIndex;
    std::map<uint32_t, std::function<int32_t()>> m_funcs;
};


// 证明在C++中也存在闭包问题，如下在lambda函数中，如果按照  lp 传入那么最终打印出来的事a的地址
// 如果按照   &lp 的方式传入，那么经过后面的地址更改，打印出来的事b的地址

int main(int argc, char *argv[]) {


    LambdaDeferTuple defer;

    defer.PushFunction([]()->int32_t {
        std::cout << "Function 1" << std::endl;
        return 0;
    });


    defer.PushFunction([]()->int32_t {
        std::cout << "Function 2" << std::endl;
        return 0;
    });

    auto index = defer.PushFunction([]()->int32_t {
        std::cout << "Function 3" << std::endl;
        return 0;
    });

    defer.PushFunction([]()->int32_t {
        std::cout << "Function 4" << std::endl;
        return 0;
    });

    defer.PopFunction(index);

    int32_t i = 3;
    do {
        LambdaDefer defer1([]()->int32_t {
            std::cout << "do while" << std::endl;
            return 0;
        });
    }
    while(i-- > 0);



    std::cout << "==================end============================" << std::endl;


    return 0;
}