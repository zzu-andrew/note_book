//
// Created by andrew on 2024/8/9.
//


#include <execinfo.h>
#include <dlfcn.h> // 用于dli_saddr
#include <cstdio>
#include <cstdlib>
#include <unistd.h> // 用于getpid()

void print_stack_trace() {
    void *callstack[128];
    char **strings;
    size_t frames;

    frames = backtrace(callstack, 128);
    strings = backtrace_symbols(callstack, frames);

    printf("Obtained %zd stack frames.\n", frames);

    for (size_t i = 0; i < frames; ++i) {
        char *mangled_name = 0;
        char *offset_begin = 0;
        char *offset_end = 0;
        char *libname = 0;

        for (char *p = strings[i]; *p; ++p) {
            if (*p == '(') mangled_name = p;
            else if (*p == '+') offset_begin = p;
            else if (*p == ')' && offset_begin != 0) offset_end = p;
            else if (*p == '[') libname = p;
        }


        printf("  %s%s+ %s%s in %s\n",
               strings[i], mangled_name ? " at " : "",
               offset_begin ? offset_begin + 1 : "", offset_end ? "" : "",
               libname ? libname + 1 : "");

    }

    free(strings);
}

void funcA() {
    printf("In funcA\n");
    print_stack_trace();
}

void funcB() {
    printf("In funcB\n");
    funcA();
}

int main() {
    printf("In main\n");
    funcB();
    return 0;
}