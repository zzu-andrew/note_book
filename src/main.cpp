//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <strings.h>
#include <thread>
#include <unordered_map>


//#include <arpa/inet.h>

using namespace std;



int isLittleEndian() {
    static unsigned short data = 0x1234;
    if (*((char*)&data) == 0x34) {
        return 1;
    }
    else {
        return 0;
    }
}


struct Data {
    union {
        uint32_t res;
        struct {
           uint8_t res1 : 4;
           uint8_t res2 : 4;
           uint8_t res3 : 4;
           uint8_t res4 : 4;
           uint8_t res5 : 4;
           uint8_t res6 : 4;
           uint8_t res7 : 4;
           uint8_t res8 : 4;
        };
    };
};




struct IPCCfg {
    std::string uuid;
    void *lpCallBack{nullptr};
    void *lpUser{nullptr};
};

struct IPCCfg1 {
    std::string uuid;
    void *lpCallBack;
    void *lpUser;
};

int main(int argc, char **argv)
{

    IPCCfg cfg{"fdata", nullptr, nullptr};



    return 0;
}