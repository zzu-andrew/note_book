//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <unordered_set>
#include <strings.h>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <queue>
#include <cstring>
#include <list>
#include <memory>
#include <cmath>
#include <array>
#include <set>
#include <future>

using namespace std;

#include <unistd.h>
#include <unordered_map>


#include <iostream>
#include <string>
#include <tuple>
#include <thread>
#include <functional>
#include <algorithm>
#include <numeric> // std::accumulate
#include <mutex>

struct  OO {

};


class Omic {
public:
    void Int() {}
  int count;
  OO o1;

};

#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>



using std::stringstream;
// 准备数据

std::string format(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const auto len = vsnprintf(nullptr, 0, fmt, args);
    va_end(args);
    std::string r;
    r.resize(static_cast<size_t>(len) + 1);
    va_start(args, fmt);
    vsnprintf(&r.front(), len + 1, fmt, args);
    va_end(args);
    r.resize(static_cast<size_t>(len));

    return r;
}



int main(int argc, char **argv) {



    std::atomic_bool boolAt;

    bool bFalse = false;

    boolAt.compare_exchange_weak(bFalse, true, std::memory_order_acquire, std::memory_order_release);










    return 0;

}