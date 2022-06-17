//
// Created by andrew on 2022/5/11.
//

#include <iostream>


using namespace std;
#include <unistd.h>


uint32_t RoundUp(uint32_t x, uint32_t align) {
    // extern有作用域在一个函数中声明extern只能在该函数中使用
    extern void Externally();
    Externally();
    return (x + align - 1) & ~ (align - 1);
}




int main(int argc, char *argv[]) {

    sleep(30);
    std::cout << RoundUp(13, 8) << endl;
    // extern也有作用域
    //Externally();




    return 0;
}

