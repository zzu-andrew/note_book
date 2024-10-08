/*

（有序区，无序区）。把无序区的第一个元素插入到有序区的合适的位置。对数组：比较得少，换得多。

插入排序思路：
1. 从第一个元素开始，该元素可以认为已经被排序
2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
5. 将新元素插入到该位置后
6. 重复步骤2~5

*/
#include <iostream>
#include <vector>

// 插入排序
void InsertSort(std::vector<int>& v) {
    int len = v.size();
    for (int i = 1; i < len; ++i) {
        int temp = v[i];  // 待插入的元素
        int j = i - 1;
        // 向前查找插入位置，并逐个后移元素
        while (j >= 0 && v[j] > temp) {
            v[j + 1] = v[j];  // 元素后移
            --j;
        }
        // 将元素插入到正确的位置
        v[j + 1] = temp;
    }
}

int main() {
    std::vector<int> v = {4, 3, 2, 1};
    InsertSort(v);

    std::cout << "Sorted array: ";
    for (const auto& num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
