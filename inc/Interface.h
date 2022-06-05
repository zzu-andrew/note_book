//
// Created by andrew on 2022/6/5.
//

#ifndef NODE_BOOKS_INTERFACE_H
#define NODE_BOOKS_INTERFACE_H
#include <iostream>

// C++纯虚函数基类实现--Interface
class Interface {
public:
    virtual ~Interface() = default;
    virtual int32_t Init() = 0;

};



#endif //NODE_BOOKS_INTERFACE_H
