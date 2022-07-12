//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <unordered_set>
#include <strings.h>
#include <map>
#include <algorithm>
#include <vector>
#include <cassert>


using namespace std;
#include <unistd.h>

class A {
public:
    virtual int GetData() = 0;

};


class B {
public:
    virtual int ShowData() = 0;
};

class C : virtual public B, virtual public A {
public:


};


class D : virtual public C {
public:
    int ShowData()  {
        std::cout << "Show " << std::endl;
        return 0;
    }

    int GetData()  {

        std::cout << "Data" << std::endl;
        return 0;
    }
};


int main(int argc, char *argv[]) {

    void* lp = new D;

    ((C*)lp)->GetData();
    ((C*)lp)->ShowData();

    ((A*)lp)->GetData();
    ((B*)lp)->ShowData();



    return 0;
}

