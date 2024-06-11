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



    std::map<int32_t, int32_t>   iPairs;
    iPairs[1] = 1;
    iPairs[1] = 2;
    iPairs[1] = 3;
    iPairs[1] = 4;
    iPairs[2] = 1;

    for (const auto& pair : iPairs) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }




    return 0;
}
