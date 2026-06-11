class LRUCache {
private:
    int size;
    list<pair<int,int>> lru;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
public:
    LRUCache(int capacity) {
        size = capacity;

    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        auto it = cache[key];
        int value = it->second;
        lru.splice(lru.begin(),lru,it);
        return value;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){ //already exist in cache
            auto it = cache[key];
            it->second = value;
            lru.splice(lru.begin(),lru,it);
        }
        else{ //need to intoduce
            if (cache.size() == size){
                auto it = prev(lru.end());
                cache.erase(it->first);
                lru.erase(it);
            }
            lru.push_front({key,value});
            cache[key] = lru.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */