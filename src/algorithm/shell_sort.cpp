//
// Created by andrew on 2024/9/8.
//


/*
 *
 * 希尔排序（Shell Sort）是一种基于插入排序的算法，但它通过将原始列表分割成多个子列表来进行排序，从而提高了插入排序的效率。希尔排序的核心思想是通过将原始列表分割成多个“间隔”（gap）来减少数据项之间的交换次数，从而加快排序速度。随着排序的进行，间隔逐渐减小，最终变为 1，此时算法退化为普通的插入排序，但由于数据已经部分有序，因此效率较高。

希尔排序的实现原理
选择间隔：首先选择一个间隔 gap，通常是数组长度的一半。
分组排序：将所有相隔 gap 的元素组成一个子列表，并对这些子列表进行插入排序。
缩小间隔：重复上述过程，每次都将间隔减半，直到间隔为 1。
最终排序：当间隔为 1 时，进行最后一次插入排序，此时数据已经较为有序，因此排序速度很快。
希尔排序的步骤
选择一个间隔 gap，通常选择 gap = length / 2。
对所有相隔 gap 的元素进行插入排序。
将 gap 减半，重复步骤 2。
直到 gap 为 1 时，进行最后一次插入排序。
 * */
#include <iostream>
#include <vector>


// 希尔排序：每一轮按照事先决定的间隔进行插入排序，间隔会依次缩小，最后一次一定要是1。
template<typename T>
void shell_sort(T array[], int length) {
    int h = 1;
    while (h < length / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                std::swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}


int main() {
    // 测试常规选择排序
    std::vector<int> v = {29, 10, 14, 37, 14};



    return 0;
}
