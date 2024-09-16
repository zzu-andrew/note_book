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
using namespace std;

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>




class Base {
public:
    virtual void func() { std::cout << "Base func()" << std::endl; }

private:
    int iCount;  // 整数计数
};

class Derived1 : virtual public Base {
public:
    virtual void func() override { std::cout << "Derived1 func()" << std::endl; }
};

class Derived2 : virtual public Base {
public:
    virtual void func() override { std::cout << "Derived2 func()" << std::endl; }
};

class Combined : public Derived1, public Derived2 {
public:
    void func() override { std::cout << "Combined func()" << std::endl; }
};






int main() {



    Derived1 derived_1;
    Derived2 derived_2;
    Combined combined;










    return 0;
}