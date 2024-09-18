/*

（有序区，无序区）。在无序区里找一个最小的元素跟在有序区的后面。对数组：比较得多，换得少。

选择排序思路：
1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
3. 以此类推，直到所有元素均排序完毕

*/

#include <iostream>
#include <vector>
#include <algorithm>  // std::swap

// 选择排序
void SelectionSort(std::vector<int>& v) {
    int len = v.size();
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (v[j] < v[min]) {  // 找到最小元素
                min = j;
            }
        }
        if (i != min) {
            std::swap(v[i], v[min]);  // 将最小元素与当前元素交换
        }
    }
}


// 模板实现选择排序
template<typename T>
void Selection_Sort(std::vector<T>& arr) {
    int len = arr.size();
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (i != min) {
            std::swap(arr[i], arr[min]);  // 交换最小元素到当前排序位置
        }
    }
}

int main() {
    // 测试常规选择排序
    std::vector<int> v = {29, 10, 14, 37, 14};
    SelectionSort(v);
    std::cout << "After regular selection sort: ";
    for (const auto& n : v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // 测试模板选择排序
    std::vector<double> v2 = {29.5, 10.1, 14.3, 37.2, 14.8};
    Selection_Sort(v2);
    std::cout << "After template selection sort: ";
    for (const auto& n : v2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}


