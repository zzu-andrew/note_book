/*

（小数，基准元素，大数）。在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。

快速排序思路：
1. 选取第一个数为基准
2. 将比基准小的数交换到前面，比基准大的数交换到后面
3. 对左右区间重复第二步，直到各区间只有一个数

*/

// ----------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

// 快速排序（递归）
void QuickSort(std::vector<int>& v, int low, int high) {
    if (low >= high) return;  // 递归结束条件

    int first = low;
    int last = high;
    int key = v[first];  // 基准元素

    while (first < last) {
        // 从右侧找到比基准小的元素，移到左边
        while (first < last && v[last] >= key)
            last--;
        if (first < last)
            v[first++] = v[last];

        // 从左侧找到比基准大的元素，移到右边
        while (first < last && v[first] <= key)
            first++;
        if (first < last)
            v[last--] = v[first];
    }

    v[first] = key;  // 将基准元素放到最终位置

    QuickSort(v, low, first - 1);  // 递归排序左半部分
    QuickSort(v, first + 1, high);  // 递归排序右半部分
}


// ----------------------------------------------------

// 快速排序的递归实现模板
template <typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end) return;

    T pivot = arr[end];  // 选择最后一个元素为基准
    int left = start, right = end - 1;

    while (left < right) {
        while (arr[left] < pivot && left < right) left++;
        while (arr[right] >= pivot && left < right) right--;
        std::swap(arr[left], arr[right]);
    }

    if (arr[left] >= pivot)
        std::swap(arr[left], arr[end]);
    else
        left++;

    quick_sort_recursive(arr, start, left - 1);  // 左半部分递归
    quick_sort_recursive(arr, left + 1, end);    // 右半部分递归
}

// 快速排序的模板接口
template <typename T>
void quick_sort(T arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}


// ----------------------------------------------------
#include <stack>

// 区间结构体
struct Range {
    int start, end;
    Range(int s, int e) : start(s), end(e) {}
};

// 迭代实现的快速排序模板
template <typename T>
void quick_sort_iterative(T arr[], int len) {
    if (len <= 0) return;

    std::stack<Range> s;
    s.push(Range(0, len - 1));

    while (!s.empty()) {
        Range range = s.top();
        s.pop();

        if (range.start >= range.end) continue;

        T pivot = arr[range.end];
        int left = range.start, right = range.end - 1;

        while (left < right) {
            while (arr[left] < pivot && left < right) left++;
            while (arr[right] >= pivot && left < right) right--;
            std::swap(arr[left], arr[right]);
        }

        if (arr[left] >= arr[range.end])
            std::swap(arr[left], arr[range.end]);
        else
            left++;

        s.push(Range(range.start, left - 1));  // 左半部分入栈
        s.push(Range(left + 1, range.end));    // 右半部分入栈
    }
}


int main() {
    //----------------------------- 递归快速排序
    std::vector<int> v = {10, 7, 8, 9, 1, 5};
    QuickSort(v, 0, v.size() - 1);

    std::cout << "Sorted array: ";
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //------------------------模板快速排序
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //------------------------- 模板快速排序迭代 -- -

    quick_sort_iterative(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
