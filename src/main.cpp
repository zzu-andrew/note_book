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


int main(int argc, char* argv[]) {




    std::map<int, int> IntMap;

    IntMap.insert(std::make_pair(1,3));

    auto iter = IntMap.find(2);
    if (iter == IntMap.end()) {
        IntMap.erase(iter);
    }

    std::vector<int> IntVector;
    IntVector.insert();







    return 0;
}