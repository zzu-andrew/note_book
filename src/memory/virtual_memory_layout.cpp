//
// Created by wangyz38535 on 2024/9/25.
//

// virtual memory layout display

#include <stdio.h>
#include <stdlib.h>
#define PRINT_DELIMITER() printf("------------------------\n");
#define PRINT_MEM_SEG(seg, addr) printf("[%s]: %p\n", seg, addr);
static void func(void)
{
    printf("hello\n");
}

int main(int argc, char *argv[])
{
    PRINT_DELIMITER();
    PRINT_MEM_SEG("CMD LINE ARGS", &argv[0]);
    int stack_var = 25;
    PRINT_DELIMITER();
    PRINT_MEM_SEG("STACK", &stack_var);
    int *heap_ptr = static_cast<int *>(malloc(sizeof(int)));
    PRINT_DELIMITER();
    PRINT_MEM_SEG("HEAP", heap_ptr);
    static int data_var = 10;
    PRINT_DELIMITER();
    PRINT_MEM_SEG("DATA", &data_var);
    PRINT_DELIMITER();
    PRINT_MEM_SEG("TEXT", func);
    return 0;
}