//
// Created by andrew on 2024/5/19.
//

#include "allocator.h"




int main(int argc, char *argv[]) {


    Allocator allocator;


    for (int i = 0; i < 1000; i ++) {
        printf("i = %d,   %p\n",i,  allocator.allocate(7));
    }



    return 0;
}


