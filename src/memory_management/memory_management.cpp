//
// Created by andrew on 2022/6/3.
//

#include "memory_management.h"

#include<iostream>


using namespace std;


// PlacementNew 测试
void PlacementNew() {
    char *buffer = new char[sizeof(MemoryManagement) * 3];

    auto *lp1 = new(buffer) MemoryManagement;
    auto *lp2 = new(buffer + sizeof(MemoryManagement)) MemoryManagement;
    auto *lp3 = new(buffer + sizeof(MemoryManagement) * 2) MemoryManagement;

    // 如果需要析枸，需要自己调用析枸函数
    lp1->~MemoryManagement();
    lp2->~MemoryManagement();
    lp3->~MemoryManagement();

    delete[] buffer;
}





int main(int argc, char * argv[]) {

    // PlacementNew 测试
    PlacementNew();

    const MemoryManagement memoryManagement;
    memoryManagement.GetCount();
    //MemoryManagement.SetCount();

    // 纯虚函数实现的基类实现
    Implementation implementation;











    return 0;
}






