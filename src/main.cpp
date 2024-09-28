#include <cctype>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <utility>  // for std::forward()
#include <memory>
#include <functional>
#include <algorithm>
#include <sstream>
#include <atomic>
#include <iostream>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <condition_variable>
#include <algorithm>
#include <unordered_map>


using namespace std;


const char * const SubStatusStr[] = {"init", "subscribe", "subscribed", "deleteting", "firstSub"};



int main(int argc, char* argv[]) {



    std::atomic<uint32_t> iCount;

    iCount.store(108);

    iCount.store(iCount.load() % 100);

    std:cout << iCount << std::endl;


    return 0;
}