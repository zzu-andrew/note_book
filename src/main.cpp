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



    std::vector<int> v = {1};

    // 打印原始排列
    std::cout << "Original permutation: ";
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';

    // 生成并打印所有排列
    do {
        for (int n : v)
            std::cout << n << ' ';
        std::cout << '\n';
    } while (std::next_permutation(v.begin(), v.end()));

    return 0;


    return 0;
}
