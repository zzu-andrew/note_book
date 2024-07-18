#include <cctype>
#include <string>
#include <iostream>
#include <utility>
#include <vector>

#include <set>
#include <map>
#include <utility>  // for std::forward()
#include <memory>
#include <functional>
#include <algorithm>
#include <sstream>
#include <atomic>
#include <iostream>
#include <unistd.h>
#include <cerrno>

using namespace std;

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>


int main() {

    std::mutex mtx;
    std::condition_variable cv;
    bool dataReady = false;

    std::unique_lock<std::mutex> lck(mtx);
    // 等待直到dataReady为true或超时
    if (!cv.wait_for(lck, std::chrono::seconds(5), []{ return false; })) {
        std::cout << "timeout " << std::endl;
    } else {
        std::cout << "dataReady..." << std::endl;
    }

    return 0;
}