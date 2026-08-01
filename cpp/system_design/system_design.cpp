/**
 * System Design Implementations — C++20
 * =======================================
 * LRU Cache, Thread-safe queue concepts
 */
#include <iostream>
#include <list>
#include <unordered_map>
#include <optional>
#include <stdexcept>

namespace dsa {

/**
 * LRU Cache
 * Time: O(1) get and put
 * Space: O(capacity)
 */
class LRUCache {
    int capacity;
    std::list<std::pair<int,int>> cache; // {key, value} MRU at front
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> map;

public:
    explicit LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        cache.splice(cache.begin(), cache, map[key]); // Move to front
        return map[key]->second;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            map[key]->second = value;
            cache.splice(cache.begin(), cache, map[key]);
        } else {
            if ((int)cache.size() == capacity) {
                map.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
};

} // namespace dsa

#if !defined(UNIT_TESTING)
int main() {
    dsa::LRUCache cache(2);
    cache.put(1, 1); cache.put(2, 2);
    std::cout << cache.get(1) << "\n";  // 1
    cache.put(3, 3);                     // Evicts key 2
    std::cout << cache.get(2) << "\n";  // -1
    cache.put(4, 4);                     // Evicts key 1
    std::cout << cache.get(1) << "\n";  // -1
    std::cout << cache.get(3) << "\n";  // 3
    std::cout << cache.get(4) << "\n";  // 4
    return 0;
}
#endif // UNIT_TESTING
