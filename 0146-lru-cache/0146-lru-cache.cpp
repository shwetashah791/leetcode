class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        } else {
            auto value = map[key]->second;
            cache.erase(map[key]);
            cache.push_front({key, value});
            map[key] = cache.begin();
            return value;
        }
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            cache.erase(map[key]);
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
        if (cache.size() > capacity) {
            map.erase(cache.back().first);
            cache.pop_back();
        }
    }
};
