#include <cctype>
#include <string>
#include <iostream>
#include <utility>
#include <vector>


#include <map>

class Inter {
public:
    virtual int GetData(int ) = 0;
    virtual int GetData() = 0;
};

class Derived : public Inter {
public:
    explicit  xDerived(int num) {}

};


void Convert(Derived de) {

}


int main() {

    int data = 102;


    return 0;
}
