class LRUCache {
    int cap;
    list<pair<int, int>> cache; 
    unordered_map<int, list<pair<int, int>>::iterator> m; 

public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        cache.splice(cache.begin(), cache, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->second = value;
            cache.splice(cache.begin(), cache, m[key]);
            return;
        }
        if (cache.size() == cap) {
            m.erase(cache.back().first); 
            cache.pop_back();            
        }
        cache.push_front({key, value});
        m[key] = cache.begin();
    }
};