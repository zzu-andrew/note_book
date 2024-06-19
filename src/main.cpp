#include <cctype>
#include <string>
#include <iostream>
#include <utility>
#include <vector>

#include <set>
#include <map>
#include <utility>  // for std::forward()
#include <memory>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[]) {

    uint32_t uIndex = 0;
    uIndex = uIndex - 1;
    std::cout << uIndex << std::endl;

    int32_t index = uIndex;

    std::cout << index << std::endl;


    uIndex = index;
    std::cout << uIndex << std::endl;


    index = 2147483647;
    std::cout << index++ << std::endl;
    uIndex = index;
    std::cout << uIndex << std::endl;
    std::cout << index++ << std::endl;

    return 0;
}
