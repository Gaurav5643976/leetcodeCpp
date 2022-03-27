class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> um;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(um.find(val)==um.end()){
            v.push_back(val);
            um[val]=v.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(um.find(val)==um.end()){
            return false;
        }
        int lastElement=v.back();
        um[lastElement]=um[val];
        v[um[val]]=lastElement;
        v.pop_back();
        um.erase(val);
        return true;
    }
    
    int getRandom() {
        int indx=rand()%v.size();
        return v[indx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */