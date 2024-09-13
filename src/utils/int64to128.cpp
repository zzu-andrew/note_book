//
// Created by wangyz38535 on 2024/9/13.
//

#include <cstdint> // 包含 int64_t
#include <iostream>

class Int128 {
public:
    explicit Int128(int64_t high = 0, int64_t low = 0) : high_(high), low_(low) {}

    // 重载赋值运算符
    Int128& operator=(const Int128& other) {
        high_ = other.high_;
        low_ = other.low_;
        return *this;
    }

    // 重载加法运算符
    Int128 operator+(const Int128& other) const {
        Int128 result(*this);
        result += other;
        return result;
    }

    // 重载加法赋值运算符
    Int128& operator+=(const Int128& other) {
        int64_t newLow = low_ + other.low_;
        high_ += (newLow < low_) ? 1 : 0; // 进位处理
        low_ = newLow;
        return *this;
    }

public:
    int64_t high_; // 高64位
    int64_t low_;  // 低64位
};

int main() {
    Int128 a(0x1234567890ABCDEF, 0x1234567890ABCDEF);
    Int128 b(0xFEDCBA9876543210, 0xFEDCBA9876543210);
    Int128 c = a + b;

    // 输出结果
    std::cout << "High part of result: " << c.high_ << std::endl;
    std::cout << "Low part of result: " << c.low_ << std::endl;

    return 0;
}