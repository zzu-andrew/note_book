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


#include <cstring>


struct X {
    typedef float type;
};

struct Y {
    typedef float type2;
};

template <typename T, typename U>
void foo(T t, typename U::type u) {
    // ...
}

void callFoo() {
    foo<int, X>(5, 5.0); // T == int, typename U::type == X::type == float
    foo<int, Y>(5, 5.0); // ???
}

int main(int argc, char **argv)
{










    return 0;
}