#include <iostream>
#include <vector>
using namespace std;

// 生成斐波那契数列，直到其值超过n
vector<int> fibonacci(int n) {
    vector<int> fib = {0, 1};  // 初始斐波那契数列
    while (fib.back() < n) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]); // 生成新的斐波那契数
    }
    return fib;
}

// 斐波那契查找函数
int fibonacciSearch(const vector<int>& arr, int x) {
    int n = arr.size();
    vector<int> fib = fibonacci(n);  // 获取斐波那契数列

    // 初始化斐波那契查找的三个关键数值
    int fibM = fib.size() - 1;  // 最大的斐波那契数对应的索引
    int fibMm1 = fibM - 1;      // 斐波那契数列中倒数第二个数
    int fibMm2 = fibM - 2;      // 斐波那契数列中倒数第三个数

    int offset = -1;  // 初始偏移量，表示检查的范围

    // 斐波那契查找的主循环
    while (fibM > 1) {
        // 检查位置i
        int i = min(offset + fibMm2, n - 1);

        // 如果目标大于当前位置的值，向右查找
        if (arr[i] < x) {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - 2;
            offset = i;  // 更新偏移量
        }
            // 如果目标小于当前位置的值，向左查找
        else if (arr[i] > x) {
            fibM = fibMm2;
            fibMm1 = fibMm2 - 1;
            fibMm2 = fibM - 2;
        }
            // 找到目标，返回其索引
        else {
            return i;
        }
    }

    // 检查最后的一个元素
    if (fibMm1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    // 未找到，返回-1
    return -1;
}

int main() {
    vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int x = 85;  // 要查找的目标值

    int index = fibonacciSearch(arr, x);
    if (index != -1) {
        cout << "元素" << x << "位于索引" << index << endl;
    } else {
        cout << "元素" << x << "未找到" << endl;
    }

    return 0;
}
