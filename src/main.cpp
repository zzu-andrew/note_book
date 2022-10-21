//
// Created by andrew on 2022/5/11.
//

#include <iostream>
#include <unordered_set>
#include <strings.h>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <queue>
#include <cstring>
#include <list>
#include <memory>
#include <cmath>

#include <set>

using namespace std;

#include <unistd.h>
#include <unordered_map>


/// 主要利用的还是模板的嵌套， 模板会优先寻找特化实现在寻找泛化实现
#include <iostream>
#include <string>
#include <tuple>

// Using expression templates to concatenate strings

template <typename... Strings>
class lazy_string_concat_helper;

// 特化实现
template <typename LastString, typename... Strings>
class lazy_string_concat_helper<LastString,
        Strings...> {
private:
    // 直接使用存储，每层模板嵌套都会有一个data保存
    // 使用保存而不是引用的好处就是无论在任何地方使用，都可以直接使用
    // 因为真正调用的地方原先的临时数据可能已经释放掉了
    LastString data;

    // 尾部，里面可能是多层模板的嵌套
    lazy_string_concat_helper<Strings...> tail;

public:
    lazy_string_concat_helper(
            LastString data,
            lazy_string_concat_helper<Strings...> tail)
            : data(std::move(data))
            , tail(std::move(tail))
    {
    }

    // Calculates the size of all strings combined
    int size() const
    {
        return data.size() + tail.size();
    }

    // The structure stores strings in reverse order: the data
    // member variable contains the string that comes last,
    // so it needs to go to the end of the buffer.
    template <typename It>
    void save(It end) const
    {
        const auto begin = end - data.size();
        std::copy(data.cbegin(), data.cend(),
                  begin);
        // 模板迭代，有多层模板就迭代多少次
        tail.save(begin);
    }

    // When you want to convert the expression definition into a real string,
    // allocate enough memory and start copying the strings into it.
    // 需要特别注意的点， std::string std::out 等也是能够进行重载的，重载之后所有字符串默认转换都会调用该函数
    operator std::string() const
    {
        std::string result(size(), '\0');
        save(result.end());
        return result;
    }

    // Creates a new instance of the structure with one string added to it
    lazy_string_concat_helper<std::string,
            LastString,
            Strings...>
    operator+(const std::string& other) const
    {
        return lazy_string_concat_helper
                <std::string, LastString, Strings...>(
                other,
                *this
        );
    }
};


// 泛化实现，当模板嵌套找不到嵌套层次时走到这里
template <>
class lazy_string_concat_helper<> {
public:
    lazy_string_concat_helper()
    {
    }
    // 最终的save会调用一下该函数
    int size() const
    {
        return 0;
    }

    template <typename It>
    void save(It) const
    {
    }
    // 当使用该类型进行 + 时会进行如下操作
    //
    lazy_string_concat_helper<std::string>
    operator+(const std::string& other) const
    {
        return lazy_string_concat_helper<std::string>(
                other,
                *this
        );
    }
};


template <typename Stream, typename... Strings>
Stream& operator<<(Stream& stream,
                   const lazy_string_concat_helper<Strings...>& strings)
{
    return stream << static_cast<std::string>(strings);
}

lazy_string_concat_helper<> lazy_concat;

class Str : public std::string {
public:
    Str() {
        std::cout << "Created" << std::endl;
    }
    Str(const Str&) {
        std::cout << "Copy" << std::endl;
    }
    ~Str() {
        std::cout << "Des" << std::endl;
    }


};
#include <initializer_list>

template<typename T1, typename T2>
struct P
{
    T1 & t1;
    T2 & t2;
};

int main(int argc, char* argv[])
{

    std::unordered_map<std::string, std::string>  strMap;


    strMap.insert(std::make_pair("x2", "x"));
    strMap.insert(std::make_pair("x1", "x"));
    strMap.insert(std::make_pair("x3", "x"));
    strMap.insert(std::make_pair("x5", "x"));
    strMap.insert(std::make_pair("x6", "x"));

    auto it = strMap.find("x");
    if (it != std::end(strMap))
    {

    }



}
