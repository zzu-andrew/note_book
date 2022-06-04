//
// Created by andrew on 2022/6/3.
//

#ifndef NODE_BOOKS_MEMORY_MANAGEMENT_H
#define NODE_BOOKS_MEMORY_MANAGEMENT_H

#include <iostream>

using namespace std;

class MemoryManagement {
public:
    MemoryManagement() {
        cout << "Creat memory_management" << endl;
    };
    ~MemoryManagement() {
        cout << "delete memory_management" << endl;
    };


private:



};


#endif //NODE_BOOKS_MEMORY_MANAGEMENT_H
