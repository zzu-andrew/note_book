//
// Created by wangyz38535 on 2022/6/7.
//

#include "exception_sample.h"

using namespace std;

// 使用 new (nothrow)只能保证new的过程，申请内存的时候不会抛出异常，要是构造函数中有异常抛出
// 同样需要进行捕获否则也会导致异常
void NoThrowExceptionSample() {
    auto lpException = new (std::nothrow) ExceptionSample;
    if (!lpException) {
        cout << "lpException is nullptr" << endl;
        return;
    }
}
// output:
// what():  Throw an runtime_error




int main(int argc, char * argv[]) {

    NoThrowExceptionSample();

    return 0;
}
