#include <iostream>
#include <vector>

// 合并两个已排序的子数组
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // 左子数组的长度
    int n2 = right - mid;     // 右子数组的长度

    // 创建临时数组
    std::vector<int> L(n1), R(n2);

    // 复制数据到临时数组 L[] 和 R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组回到原数组 arr[]
    int i = 0;  // 初始索引第一个子数组
    int j = 0;  // 初始索引第二个子数组
    int k = left;  // 初始索引合并后的子数组

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制 L[] 的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 复制 R[] 的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序
void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // 找到中间索引
        int mid = left + (right - left) / 2;

        // 对左边的子数组进行递归排序
        merge_sort(arr, left, mid);

        // 对右边的子数组进行递归排序
        merge_sort(arr, mid + 1, right);

        // 合并两个子数组
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    int n = arr.size();

    merge_sort(arr, 0, n - 1);

    std::cout << "Sorted array is: \n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}