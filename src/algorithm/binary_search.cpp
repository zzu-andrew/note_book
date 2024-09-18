//
// Created by andrew on 2024/8/25.
//

#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
using namespace std;




int32_t BinarySearch(const int32_t array[], int32_t left, int32_t right, int32_t key) {

    // 为了兼容只有一个元素的情况需要 left <= right的情况进行判断
    while (left <= right) {
        int32_t mid = (right + left) / 2;
        // 1. 相等
        if (array[left] == key) {
            return mid;
        } else if (key > array[mid]) {
            // 2. 大于
            left = mid + 1;
        } else {
        //    3. 小于
            right = mid - 1;

        }
    }

    return -1;    // key is not find
}



// 递归
int BinarySearch2(vector<int> v, int value, int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (v[mid] == value)
        return mid;
    else if (v[mid] > value)
        return BinarySearch2(v, value, low, mid - 1);
    else
        return BinarySearch2(v, value, mid + 1, high);
}





TEST(DemoAlgo, binarySearch) {

    std::vector<int32_t> array{1,4,5,6,7,8,12,34,45};

    EXPECT_EQ(3, BinarySearch(&array[0], 0, array.size(), 6));
    EXPECT_EQ(-1, BinarySearch(&array[0], 0, array.size(), 32));

    std::vector<int32_t> array1{1};
    // 只有一个元素的也要支持
    EXPECT_EQ(0, BinarySearch(&array1[0], 0, array1.size(), 1));
    // 找不到就返回-1


    EXPECT_EQ(-1, BinarySearch(&array1[0], 0, array.size(), 3));

}

