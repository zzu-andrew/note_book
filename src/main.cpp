//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <unordered_set>
#include <strings.h>
#include <map>
#include <algorithm>
#include <vector>


using namespace std;
#include <unistd.h>


uint32_t RoundUp(uint32_t x, uint32_t align) {
    // extern有作用域在一个函数中声明extern只能在该函数中使用
    extern void Externally();
    Externally();
    return (x + align - 1) & ~ (align - 1);
}




int main(int argc, char *argv[]) {

    std::string name = "ahdjgk;";

    std::cout << "test" << std::endl;

    RoundUp(12, 8);

    std::cout << name.substr(0, name.size() - 1);


    sleep(100);

    return 0;
}

