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

// 算法复杂度 O(logn)
// 2. 查询原有数组下标



class Solution {
public:
    // nums 是旋转之后的数组
    int search(vector<int>& nums, int target) {
        // 异常情况
        // 1. 数组为空， 2. ？
        if (nums.empty()) {
            return -1;
        }


        // 2. 定位target  O(logn) 算法要求，需要使用二分查找
        int left = 0;
        int right = nums.size() - 1;
        // 先查看中间值
        int middle = 0;
        while (left < right) {
            // 每次循环需要重新定位中间值
            middle = (left + right) / 2;

            //
            if (nums[middle] == target) {
                return middle;
            }



            // 其他情况

            if (nums[left] <= nums[middle]) {
                if (target < nums[middle]) {
                    right = middle ;
                }
                else {
                    left = middle;
                }
            }
            // 小于是乱序，大于是有序之后的后半段
            if (nums[right] )

        }






        return -1;
    }
};




int main() {

    Solution solution;

    std::vector<int> num{4,5,6,7,0,1,2};


    std::cout << solution.search(num, 0) << std::endl;





    return 0;
}