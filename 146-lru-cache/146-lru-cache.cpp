class LRUCache {
private:
    //typedef list<int> LI;
    //typedef pair<int, list<int>::iterator> PII;
    //typedef unordered_map<int, pair<int, list<int>::iterator>> HIPII;
    
    void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> used;
    int _capacity;
public:
    LRUCache(int capacity){
        _capacity=capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()){
            return -1;
        } 
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()){
             touch(it);
        }
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
};