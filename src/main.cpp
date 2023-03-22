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


#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <unordered_map>

using namespace std;


#include <atomic>
#include <thread>
#include <cassert>
#include <string_view>


// C convention
void TasksCharStar(const char* s) {
}

// old standard c++ convention
void TaskString(const std::string& s) {
}

// string_view C++ convention
void TaskStringView(std::string_view s) { // c++ 17

    std::string name = "date";
    s = name;

}

class LambdaDefer {
public:
    explicit LambdaDefer(std::function<int32_t ()> && func) : m_func(func){}

    ~LambdaDefer() {
        if (m_func) {
            m_func();
        }
    }

private:
    std::function<int32_t ()> m_func;
};



int main(int argc, char **argv) {


    TaskStringView("neNamem");

    return 0;
}