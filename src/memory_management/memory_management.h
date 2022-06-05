//
// Created by andrew on 2022/6/3.
//

#ifndef NODE_BOOKS_MEMORY_MANAGEMENT_H
#define NODE_BOOKS_MEMORY_MANAGEMENT_H

#include <iostream>
#include "Interface.h"

using namespace std;

class MemoryManagement {
public:
    MemoryManagement() {
        cout << "Creat memory_management" << endl;
    };
    ~MemoryManagement() {
        cout << "delete memory_management" << endl;
    };

    // const修饰的函数，说明这个函数不能修改任何成员变量
    // 其实这里的const是用来修饰隐含参数this指针用的
    uint32_t GetCount() const {
        return m_count;
    }
    void SetCount(uint32_t count) {
        m_count = count;
    }

private:
    uint32_t m_count{};

};


class Implementation : public Interface {
public:
    int32_t Init() override {
        return 0;
    }
};





#endif //NODE_BOOKS_MEMORY_MANAGEMENT_H
