//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <unordered_set>
#include <strings.h>
#include <map>
#include <algorithm>
#include <vector>
#include <cassert>


using namespace std;
#include <unistd.h>


uint32_t RoundUp(uint32_t x, uint32_t align) {
    // extern有作用域在一个函数中声明extern只能在该函数中使用
    extern void Externally();
    Externally();
    return (x + align - 1) & ~ (align - 1);
}

/*
 * Check at compile time that something is of a particular type.
 * Always evaluates to 1 so you may use it easily in comparisons.
 */
#define typecheck(type,x) \
({	type __dummy; \
	typeof(x) __dummy2; \
	(void)(&__dummy == &__dummy2); \
	1; \
})

/*
 * Check at compile time that 'function' is a certain type, or is a pointer
 * to that type (needs to use typedef for the function type.)
 */
#define typecheck_fn(type,function) \
({	typeof(type) __tmp = function; \
	(void)__tmp; \
})


int main(int argc, char *argv[]) {

    std::string name = "ahdjgk;";

    assert(typecheck(std::string, name));


    char x = 0;
    {
        int _dummy;

        typeof(x) _dummy2;

        (void)(&_dummy == &_dummy2);
	1;
}

    printf("========================%d\n", typecheck(std::string, name));

    std::cout << "test" << std::endl;

    RoundUp(12, 8);

    typeof(RoundUp) *lpFunction;
    lpFunction = RoundUp;

    std::cout << name.substr(0, name.size() - 1);

    string num = "d";


    return 0;
}

