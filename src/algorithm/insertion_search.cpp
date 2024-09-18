#include <iostream>
#include <vector>






//插值查找
int InsertionSearch(int a[], int value, int low, int high)
{
    // 根据公式计算，该值可能出现的位置
    int mid = low+(value-a[low])/(a[high]-a[low])*(high-low);
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return InsertionSearch(a, value, low, mid-1);
    if(a[mid]<value)
        return InsertionSearch(a, value, mid+1, high);

    return -1;
}


// 插值查找
int interpolation_search(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // 防止除数为零的情况
        if (arr[high] == arr[low]) {
            if (arr[low] == target) {
                return low;
            }
            break;
        }

        // 计算目标值可能的位置
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // 比较目标值与当前位置的元素
        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    // 查找失败
    return -1;
}

int main(int argc, char **argv) {





    return 0;
}
