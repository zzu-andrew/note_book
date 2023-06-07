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
#include<ctime>

long getTimeUs()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME,&ts);

    return ts.tv_sec*1000000 + ts.tv_nsec / 1000;
}

using namespace std;



int main(int argc, char **argv)
{

    std::string name = "";

    name.c_str()


    return 0;
}