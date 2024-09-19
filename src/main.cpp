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



    std::map<std::string, std::string> mapStr;


    mapStr.emplace("datassssssssssssssssssssss", "  a1111111111111111111111111111111111");
    auto insertPair = mapStr.emplace("datassssssssssssssssssssss", "  x11111111111111111111111111111111111");
    std::cout << insertPair.second << std::endl;

    std::cout << mapStr.size() << mapStr["datassssssssssssssssssssss"] << std::endl;


    //







    return 0;
}