//
// Created by andrew on 2022/6/21.
//
#include <stdio.h>
#include <unistd.h>




void PrintString(const char* str) {

    printf("%s", str);
}



int main(int argc, char **arg) {


    sleep(1);


    PrintString("test tracer");


    return 0;
}


