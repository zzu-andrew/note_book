//
// Created by andrew on 2022/6/23.
//

#include <stdio.h>


void PutString(const char* str) {
    printf("string %s\n", str);
};


int main(int argc, char *argv[]) {


    PutString(argv[0]);


    return 0;
}
