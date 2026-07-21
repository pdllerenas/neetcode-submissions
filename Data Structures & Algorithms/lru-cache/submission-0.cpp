class LRUCache {
private:
    using CacheNode = pair<int, int>;
    list<CacheNode> cache_list;
    unordered_map<int, list<CacheNode>::iterator> cache_map;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = cache_map.find(key);
        if (it != cache_map.end()) {
            cache_list.splice(cache_list.begin(), cache_list, it->second);
            return cache_map[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cache_map.find(key);
        if (it != cache_map.end()) {
            it->second->second = value;
            cache_list.splice(cache_list.begin(), cache_list, it->second);
            return;
        }
        if (cache_map.size() == capacity) {
            int lru_key = cache_list.back().first;
            cache_map.erase(lru_key);
            cache_list.pop_back();
        }
        cache_list.push_front({key, value});
        cache_map[key] = cache_list.begin();
    }
};
