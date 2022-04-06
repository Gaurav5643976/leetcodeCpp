class TimeMap {
    map<pair<string,int>,string> um;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[{key,timestamp}]=value;
    }
    
    string get(string key, int timestamp) {
        auto it=um.upper_bound({key,timestamp});
        it--;
        if((*it).first.second>timestamp or (*it).first.first!=key){
            return "";
        }
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */