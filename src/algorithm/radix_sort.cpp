/*
 *
 *
 *
基数排序（Radix Sort）是一种非比较型整数排序算法，其原理是按照低位先排序，然后收集；再按高位排序，然后再收集；依次类推，直到最高位。
 基数排序的关键在于“分配”和“收集”两个过程。
基数排序通常使用链表或者队列来实现，但在实际应用中，可以使用数组来代替。基数排序适用于整数排序，尤其是当整数的范围不是特别大时效果较好。
 基数排序的实现原理
确定最大数的位数：找到待排序数组中的最大数，并确定其位数。
按位排序：从最低位开始，依次对每一位进行排序。通常使用计数排序（Counting Sort）来对每一位进行排序。
收集结果：对每一趟排序的结果进行收集，形成新的数组

 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>

// 计数排序，用于基数排序中的按位排序
void counting_sort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // 存储每个数字的出现次数
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // 改变 count[i] 使其变成该位置的实际位置
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 建立输出数组
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // 复制输出数组到原始数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 基数排序
void radix_sort(std::vector<int>& arr) {
    // 找到最大数
    int max = *std::max_element(arr.begin(), arr.end());

    // 从最低位开始
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radix_sort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}