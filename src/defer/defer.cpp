//
// Created by wangyz38535 on 2024/4/23.
//


#include <atomic>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <set>


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

// 证明在C++中也存在闭包问题，如下在lambda函数中，如果按照  lp 传入那么最终打印出来的事a的地址
// 如果按照   &lp 的方式传入，那么经过后面的地址更改，打印出来的事b的地址

int main(int argc, char *argv[]) {

    int a = 12;
    int b = 14;
    int *lp = &a;
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    LambdaDefer defer([&lp]()->int32_t {
        printf("lp = %p\n", lp);
        return 0;
    });

    lp = &b;


    std::set<int32_t> data{a,b};

    for (auto d : data) {
        std::cout << d << std::endl;
    }



    return 0;
}