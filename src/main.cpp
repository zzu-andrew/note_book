//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <strings.h>
#include <thread>
#include <unordered_map>
#include <exception>
#include <mutex>

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

std::mutex muix;

void LockData(std::unique_lock<std::mutex>* lpLock)
{
    std::unique_lock<std::mutex> lodck(muix, std::defer_lock);

    std::cout <<  lpLock->owns_lock() << std::endl;

}


bool SafeEqual(const std::string& a, const std::string& b) {
    if (a.length() != b.length()) {
        return false;
    }


    auto length = a.length();
    int equal  = 0;
    for (auto i = 0; i < length; i++) {
        equal |= a[i] ^ b[i];
    }

    return equal == 0;
}

int main(int argc, char **argv)
{

    std::unique_lock<std::mutex> lodk(muix);
    LockData(&lodk);

    SafeEqual("data","data");


    return 0;
}