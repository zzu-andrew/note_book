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
#include <list>

using namespace std;






int main() {


    std::set<int> setAlices{1};
    std::set<int> setAlices2{2};
    std::set<int> setRet{};

    std::set_difference(setAlices2.begin(), setAlices2.end(),
                        setAlices.begin(), setAlices.end(), std::inserter(setRet, setRet.begin()));

    for (const auto& index : setRet) {
        std::cout << index << std::endl;
    }





    return 0;
}