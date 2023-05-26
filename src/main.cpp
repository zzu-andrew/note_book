//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <strings.h>

#include <unordered_map>
#include <thread>

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



int main(int argc, char **argv)
{

    //if (isLittleEndian()) {
    //    printf("little endian\n");
    //}
    //else {
    //    printf("big endian\n");
    //}
    //
    //
    //Data data{};
    //data.res1 = 1;
    //data.res2 = 2;
    //data.res3 = 3;
    //data.res4 = 4;
    //
    //data.res = htonl(data.res);
    //
    //std::cout << data.res1 << data.res2 << data.res3 << data.res4 << std::endl;

    std::unordered_map<std::string, std::string> nameMap;
    nameMap.insert(std::make_pair("", ""));




    std::cout << "std::this_thread::get_id is : " << std::this_thread::get_id() << std::endl;



    return 0;
}