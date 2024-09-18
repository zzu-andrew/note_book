#include <iostream>
#include <vector>
#include <algorithm>  // std::swap
/*

（无序区，有序区）。从无序区通过交换找出最大元素放到有序区前端。

选择排序思路：
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

*/

// 常规的冒泡排序
void BubbleSort(std::vector<int>& v) {
    int len = v.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}


// 模板实现冒泡排序
template<typename T>
void bubble_sort(T arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


// 改进版冒泡排序
void BubbleSort_orderly(std::vector<int>& v) {
    int len = v.size();
    bool orderly = false;
    for (int i = 0; i < len - 1 && !orderly; ++i) {
        orderly = true;
        for (int j = 0; j < len - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                orderly = false;  // 发生交换，则仍非有序
            }
        }
    }
}


int main() {
    std::vector<int> v = {5, 3, 8, 6, 2, 7, 4, 1};

    // 常规冒泡排序
    BubbleSort(v);
    std::cout << "After regular bubble sort: ";
    for (const auto& n : v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // 改进版冒泡排序
    std::vector<int> v2 = {5, 3, 8, 6, 2, 7, 4, 1};
    BubbleSort_orderly(v2);
    std::cout << "After improved bubble sort: ";
    for (const auto& n : v2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // 模板版排序（整型数组）
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);
    std::cout << "After template bubble sort: ";
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


