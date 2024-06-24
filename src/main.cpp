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

using namespace std;



class LambdaDeferTuple {
public:
    LambdaDeferTuple() : m_funcIndex(0), m_funcs{} {}

    ~LambdaDeferTuple() {
        for (const auto& pair : m_funcs) {
            if (pair.second) {
                pair.second();
            }
        }
    }

    uint32_t PushFunction(std::function<uint32_t()>&& func) {
        auto index = m_funcIndex.fetch_add(1);
        m_funcs.insert(std::make_pair(index, func));
        return index;
    }

    void PopFunction(uint32_t index) {
        m_funcs.erase(index);
    }

    void SetNoDefer() {
        m_funcs.clear();
    }

private:
    std::atomic<uint32_t> m_funcIndex;
    std::map<uint32_t, std::function<int32_t()>> m_funcs;
};




int main(int argc, char* argv[]) {

    LambdaDeferTuple tuple;

    int32_t  index = 0;
    tuple.PushFunction([index]()->int32_t {

        std::cout << index << std::endl;
        return 0;
    });

    index ++;
    tuple.PushFunction([index]()->int32_t {

        std::cout << index << std::endl;
        return 0;
    });

    index ++;
    tuple.PushFunction([index]()->int32_t {

        std::cout << index << std::endl;
        return 0;
    });

    index ++;
    tuple.PushFunction([index]()->int32_t {

        std::cout << index << std::endl;
        return 0;
    });

    index ++;
    tuple.PushFunction([index]()->int32_t {

        std::cout << index << std::endl;
        return 0;
    });

    index ++;
    auto funcIndex = tuple.PushFunction([index]()->int32_t {

        std::cout << index << std::endl;
        return 0;
    });

    tuple.PopFunction(funcIndex);

    index ++;
    tuple.PushFunction([index]()->int32_t {

        std::cout << index << std::endl;
        return 0;
    });




    return 0;
}
