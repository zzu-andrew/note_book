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
    const int LEN = 64*1024*1024;
    int *arr = new int[LEN];

    auto start = getTimeUs();
    //for (int i = 0; i < LEN; i += 1) arr[i] = i;
    for (int i = 0; i < LEN; i += 8) arr[i] = i;
    auto end = getTimeUs();
    std::cout << "time : " << end - start << std::endl;




    char buffer[1024];
    std::string(buffer, 1024);
    //start = getTimeUs();
    //for (int i = 0; i < LEN; i += 8) arr[i] = i;
    //end = getTimeUs();
    //std::cout << "time : " << end - start << std::endl;

}