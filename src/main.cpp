//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <strings.h>
#include <thread>
#include <unordered_map>
#include <exception>
#include <mutex>
#include <cstddef>

//#include <arpa/inet.h>

using namespace std;

class f{
public:
    void Show() {
        std::cout << "ffffffffffffffffffffffffffffffffffffff" << std::endl;
    }
};

class son : public f {
public:
    void Show(){
        std::cout << "+++++++++++++++++++++++++++++++++++++++" << std::endl;
    }
};

int main(int argc, char **argv)
{
    son s;
    f *lp = &s;
    lp->Show();
    ((son*) lp)->Show();
    return 0;
}