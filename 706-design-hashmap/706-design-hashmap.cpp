class MyHashMap {
public:
    /** Initialize your data structure here. */
    int mapp[1000001];
    MyHashMap() {
        memset(mapp,-1,sizeof(mapp));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        mapp[key]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return mapp[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        mapp[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */