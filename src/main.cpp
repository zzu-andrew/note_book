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

std::string to_lowercase(const std::string& str) {
    std::string lower_str = str;
    for (char &c : lower_str) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return lower_str;
}

bool removeTrailingCrLf(std::string& str) {
    if (!str.empty()) {
        // 检查最后两个字符是否为'\r'和'\n'
        if (str.back() == '\n' && str[str.size() - 2] == '\r') {
            // 移除最后两个字符
            str.erase(str.size() - 2);
            return true;
        } else if (str.back() == '\r') {
            // 如果只有'\r'，则移除最后一个字符
            str.pop_back();
            return true;
        } else if (str.back() == '\n') {
            // 如果只有'\n'，则移除最后一个字符
            str.pop_back();
            return true;
        }
    }
    return false;
}


std::string Rtrim(const std::string& original, const std::string& chars = "\t\n\r\v\f ")
{
    std::string str = original;
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

int main() {

    std::string name = "CONNECT\r\n";

    std::cout << name.find_last_not_of("\t\n\r\v\f ") << std::endl;

    std::cout << name.size() << name.size()-1 << std::endl;
    auto str = Rtrim(name);
    std::cout << str << std::endl;
    std::cout << str.size() << std::endl;




    return 0;
}