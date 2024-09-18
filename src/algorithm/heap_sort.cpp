#include <iostream>
#include <algorithm>
#include <vector>

// 使用标准命名空间中的函数和类型
using namespace std;

// 构建最大堆
void max_heapify(int arr[], int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        // 找出较大的子节点
        if (son + 1 <= end && arr[son] < arr[son + 1]) {
            son++;
        }
        // 如果父节点大于子节点，则不需要调整
        if (arr[dad] >= arr[son]) {
            break;
        }
        // 交换父节点和较大子节点
        swap(arr[dad], arr[son]);
        dad = son;
        son = dad * 2 + 1;
    }
}

// 堆排序
void heap_sort(int arr[], int len) {
    // 创建最大堆
    for (int i = len / 2 - 1; i >= 0; i--) {
        max_heapify(arr, i, len - 1);
    }
    // 排序
    for (int i = len - 1; i > 0; i--) {
        // 将堆顶元素（当前最大值）与最后一个元素交换
        swap(arr[0], arr[i]);
        // 重新调整剩余元素为最大堆
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}