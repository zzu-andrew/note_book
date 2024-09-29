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
#include <unordered_set>


using namespace std;



/*

 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。


 示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9


 * */


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 1. 异常判断
        if (nums.empty()) return 0;

        std::unordered_set<int> mapLoadData;
        for (const auto iData : nums) {
            mapLoadData.insert(iData);
        }
        // 最大连续个数，最少为1个
        int iMaxCunt = 1;
        for (const auto iData : nums) {
            int32_t iIndex = 0;
            auto iFindData = iData;

            // 上次查找到max之后，如果小于这个值得可以进行过滤，部分过滤

            //if (iMaxCunt > 1 && std::end(mapLoadData) == mapLoadData.find(iFindData - iMaxCunt / 2) && std::end(mapLoadData) == mapLoadData.find(iFindData + iMaxCunt / 2)) {
            //    ;
            //}
            //else
            //{
            //
            //}

            do {
                iFindData --;
                iIndex ++;
            } while (std::end(mapLoadData) != mapLoadData.find(iFindData));
            // 本身重复计算一次
            iFindData = iData;
            do {
                iFindData ++;
                iIndex ++;
            } while (std::end(mapLoadData) != mapLoadData.find(iFindData));

            iIndex --;

            iMaxCunt = std::max(iMaxCunt, iIndex);
        }


        return iMaxCunt;
    }
};


class Base {
    public:


    private:
    virtual void Show() {}
};

class Driver : private Base {
public:

};






int main(int argc, char* argv[]) {



    Driver driver;
    // 私有继承之后，子类不能转化为基类
    Base* base = &driver;
    base->Show();



    Solution solution;



    std::vector<int> vecNumbers{0,3,7,2,5,8,4,6,0,1};
    std::cout << solution.longestConsecutive(vecNumbers) << std::endl;






    return 0;
}