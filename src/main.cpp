#include <iostream>
#include <set>
#include <algorithm>

int main() {
    std::set<int> set1 {1, 2, 3};
    std::set<int> set2 {3, 2, 1};

    bool isEqual = std::equal(set1.begin(), set1.end(), set2.begin(),
                              [](const int& a, const int& b) { return a == b; });

    // 输出结果
    if (isEqual) {
        std::cout << "set1 and set2 are equal." << std::endl;
    } else {
        std::cout << "set1 and set2 are not equal." << std::endl;
    }

    std::all_of()

    return 0;
}