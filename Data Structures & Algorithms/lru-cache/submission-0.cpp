class LRUCache {
    std::list<std::pair<int, int>> cacheNodes;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;
    int capacity;

public:
    explicit LRUCache(int cap) : capacity(cap) { cacheMap.reserve(cap); }

    int get(int key) {
        int output = -1;
        if (cacheMap.find(key) != cacheMap.end()) {
            auto cacheIter = cacheMap.at(key);
            output = cacheIter->second;
            cacheNodes.erase(cacheIter);
            cacheNodes.emplace_front(key, output);
        }
        return output;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
        } else {
            cacheNodes.emplace_front(key, value);
            cacheMap.emplace(key, cacheNodes.begin());
            if (static_cast<int>(cacheMap.size()) > capacity) {
                auto [leastUsedKey, leastUsedValue] = cacheNodes.back();
                cacheMap.erase(leastUsedKey);
                cacheNodes.pop_back();
            }
        }
    }
};