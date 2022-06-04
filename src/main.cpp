//
// Created by andrew on 2022/5/11.
//

#include <iostream>


using namespace std;



uint32_t RoundUp(uint32_t x, uint32_t align) {
    return (x + align - 1) & ~ (align - 1);
}




int main(int argc, char *argv[]) {


    std::cout << RoundUp(13, 8) << endl;


    return 0;
}

