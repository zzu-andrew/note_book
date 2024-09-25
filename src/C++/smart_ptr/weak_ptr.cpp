//
// Created by wangyz38535 on 2023/12/22.
//
#include <iostream>
#include <vector>
#include <map>
#include <memory>

using namespace std;

class Child;
class Parent;

class Child {
public:
    std::shared_ptr<Parent> parentPtr;
    ~Child() { std::cout << "Child destructed\n"; }
};

class Parent {
public:
    std::weak_ptr<Child> childPtr;
    ~Parent() { std::cout << "Parent destructed\n"; }
};

// 只要上述parent地方为weak_ptr这里无论是否释放parent都能保证两个对象都被释放
void createCycle() {
    std::shared_ptr<Parent> parent = std::make_shared<Parent>();
    std::shared_ptr<Child> child = std::make_shared<Child>();
    parent->childPtr = child;
    child->parentPtr = parent;
    std::cout << parent->childPtr.use_count() << std::endl;
    std::cout << child->parentPtr.use_count() << std::endl;

}

void avoidCycle() {
    std::shared_ptr<Parent> parent = std::make_shared<Parent>();
    std::shared_ptr<Child> child = std::make_shared<Child>();
    parent->childPtr = child;
    child->parentPtr = parent;
    // 把原有parent释放，这样无论释放哪一个对象都能将对方释放
    parent.reset(); // 释放parent对象，此时child对象也会被释放 ，避免了循环引用
}


int main(int argc, char* argv[]) {
    createCycle(); // 这会导致循环引用，因此Parent和Child的析构函数不会被调用
    avoidCycle(); // 使用std::weak_ptr避免了循环引用，Parent和Child的析构函数会被正确调用

    // 用于去除数组的长度
    std::cout << std::extent<decltype(argv)>::value  << "  " << std::extent<decltype(argv)>::type::value << std::endl;

    return 0;
}
