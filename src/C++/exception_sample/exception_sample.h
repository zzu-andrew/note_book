//
// Created by wangyz38535 on 2022/6/7.
//

#ifndef NODE_BOOKS_EXCEPTION_SAMPLE_H
#define NODE_BOOKS_EXCEPTION_SAMPLE_H
#include <iostream>
#include <exception>

class ExceptionSample {
public:
    ExceptionSample() {
    //    抛出异常，可以抛出任意类型的异常，整数字符串等
        throw std::runtime_error("Throw an runtime_error");
    }
};


#endif //NODE_BOOKS_EXCEPTION_SAMPLE_H
