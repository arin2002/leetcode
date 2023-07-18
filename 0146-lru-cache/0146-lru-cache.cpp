class LRUCache {
public:
    list<int> dll; // doubly linked list in c++
    int n;
    // this is used for getting key and removing the
    // element in order 1 time
    unordered_map<int,pair<list<int>::iterator,int>> ump;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(ump.find(key) == ump.end())
            return -1;
        
        // if found we need to move it to first and update
        auto it = ump[key].first;
        int ans = ump[key].second;
        
        // remove the node as not needed O(1)
        dll.erase(it);
        // add to front -> O(1)
        dll.push_front(key);
        ump[key].first = dll.begin();
        
        return ans;
    }
    
    void put(int key, int value) {
        if(ump.find(key) != ump.end()){
            ump[key].second = value;
            dll.erase(ump[key].first);
            dll.push_front(key);
            ump[key].first = dll.begin();

            return;
        }
        
        if(dll.size()<n){
            dll.push_front(key);
            ump[key] = {dll.begin(),value};
        }
        else{
            int k = dll.back();
            dll.pop_back();
            dll.push_front(key);
            ump[key] = {dll.begin(),value};
            ump.erase(k); 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */