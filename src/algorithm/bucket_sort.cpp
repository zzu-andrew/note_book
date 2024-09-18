#include<iterator>
#include<iostream>
#include<vector>
using std::vector;

/*****************

桶排序：将值为i的元素放入i号桶，最后依次把桶里的元素倒出来。

桶排序序思路：
1. 设置一个定量的数组当作空桶子。
2. 寻访序列，并且把项目一个一个放到对应的桶子去。
3. 对每个不是空的桶子进行排序。
4. 从不是空的桶子里把项目再放回原来的序列中。

假设数据分布在[0，100)之间，每个桶内部用链表表示，在数据入桶的同时插入排序，然后把各个桶中的数据合并。

*****************/


#include <iostream>
#include <vector>
#include <algorithm> // for sort

// 桶排序
void bucket_sort(std::vector<float>& arr) {
    if (arr.empty()) {
        return;
    }

    // 确定最大值和最小值
    float min = *std::min_element(arr.begin(), arr.end());
    float max = *std::max_element(arr.begin(), arr.end());

    // 计算桶的数量
    size_t bucket_count = arr.size();
    std::vector<std::vector<float>> buckets(bucket_count);

    // 将元素分配到桶中
    for (float value : arr) {
        // 计算桶的索引
        size_t index = static_cast<size_t>((value - min) / (max - min + 1) * (bucket_count - 1));
        buckets[index].push_back(value);
    }

    // 对每个桶进行排序
    size_t sorted_index = 0;
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        for (float value : bucket) {
            arr[sorted_index++] = value;
        }
    }
}

int main() {
    // 按照值进行排序
    std::vector<float> arr = {0.78f, 0.17f, 0.39f, 0.26f, 0.72f, 0.94f, 0.21f, 0.12f, 0.23f, 0.68f};

    std::cout << "Original array: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bucket_sort(arr);

    std::cout << "Sorted array: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
