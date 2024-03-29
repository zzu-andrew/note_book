#include <cctype>
#include <string>
#include <iostream>
#include <utility>
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

void createCycle() {
    std::shared_ptr<Parent> parent = std::make_shared<Parent>();
    std::shared_ptr<Child> child = std::make_shared<Child>();
    parent->childPtr = child;
    child->parentPtr = parent;
}

void avoidCycle() {
    std::shared_ptr<Parent> parent = std::make_shared<Parent>();
    std::shared_ptr<Child> child = std::make_shared<Child>();
    parent->childPtr = child;
    child->parentPtr = parent;
    parent.reset(); // 释放parent对象，此时child对象也会被释放，避免了循环引用
}

int main(int argc, char* argv[]) {

    createCycle(); // 这会导致循环引用，因此Parent和Child的析构函数不会被调用
    avoidCycle(); // 使用std::weak_ptr避免了循环引用，Parent和Child的析构函数会被正确调用


    return 0;
}
