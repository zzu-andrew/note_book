#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <list>
#include <unordered_map>
#include <cstddef>

using namespace std;

template<typename key_t, typename value_t>
class LruCache {
public:
    typedef typename std::pair<key_t, value_t> key_value_pair_t;
    typedef typename std::list<key_value_pair_t>::iterator list_iterator_t;

    explicit LruCache(size_t maxSize) :
            m_maxSize(maxSize) {
    }

    void Put(const key_t& key, const value_t& value) {
        auto it = m_cacheItemsMap.find(key);
        m_cacheItemsList.push_front(key_value_pair_t(key, value));
        if (it != m_cacheItemsMap.end()) {
            m_cacheItemsList.erase(it->second);
            m_cacheItemsMap.erase(it);
        }
        m_cacheItemsMap[key] = m_cacheItemsList.begin();

        if (m_cacheItemsMap.size() > m_maxSize) {
            auto last = m_cacheItemsList.end();
            last--;
            m_cacheItemsMap.erase(last->first);
            m_cacheItemsList.pop_back();
        }
    }

    value_t Get(const key_t& key) {

        auto it = m_cacheItemsMap.find(key);
        if (it == m_cacheItemsMap.end()) {
            return value_t{};
        } else {
            // 将最新的节点提前
            m_cacheItemsList.splice(m_cacheItemsList.begin(), m_cacheItemsList, it->second);
            return it->second->second;
        }
    }

    template<typename Add>
    void UpdateCache(const key_t& key, Add add) {

        auto it = m_cacheItemsMap.find(key);
        if (it == m_cacheItemsMap.end()) {
        } else {
            // 将内部元素指定的值移动到开头，这种一定效率特别高
            m_cacheItemsList.splice(m_cacheItemsList.begin(), m_cacheItemsList, it->second);
            add(it->second->second);
        }
    }

    bool Exists(const key_t& key) const {
        return m_cacheItemsMap.find(key) != m_cacheItemsMap.end();
    }

    size_t Size() const {
        return m_cacheItemsMap.size();
    }

    // TODO：优化 采用加锁引用的方式避免复制
    std::list<key_value_pair_t> GetLruList() const {
        return m_cacheItemsList;
    }

private:
    // 这里借用，list移动只要不更改当前值，原有的迭代器就有效
    std::list<key_value_pair_t> m_cacheItemsList;
    std::unordered_map<key_t, list_iterator_t> m_cacheItemsMap;
    size_t m_maxSize;
};

int main(int argc, char* argv[]) {

    auto cache_lru = new LruCache<int, int>(100);
    cache_lru->Put(1, 777);
    cache_lru->Put(2, 777);
    cache_lru->Put(3, 777);
        cache_lru->Put(4, 774324327);
        cache_lru->Put(5, 12313);
        cache_lru->Put(3, 123);
        cache_lru->Put(3, 3424);

    cache_lru->UpdateCache(3, [](int &data) {
        data ++;
    });

    cache_lru->Get(3);
    auto list = cache_lru->GetLruList();

    for (auto & l : list)
    {
        std::cout << l.first << std::endl;
    }
    delete cache_lru;
    return 0;
}