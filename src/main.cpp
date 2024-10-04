#include <cctype>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <utility>  // for std::forward()
#include <memory>
#include <functional>
#include <algorithm>
#include <sstream>
#include <atomic>
#include <iostream>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <condition_variable>
#include <algorithm>
#include <unordered_map>


using namespace std;


const char * const SubStatusStr[] = {"init", "subscribe", "subscribed", "deleteting", "firstSub"};

class MyClass {
public:
    MyClass(int value) : data(value) {}

    virtual void printData() const {
        //std::cout << data << std::endl;
    }

private:
    int data;
};

class MyClass1 {
public:
    MyClass(int value) : data(value) {}

    virtual void printData() const {
        //std::cout << data << std::endl;
    }

private:
    int data;
};


int main() {
    MyClass *lpObj = new MyClass(1);

    // 调用成员函数
    lpObj->printData();  // 静态绑定调用

    return 0;
}