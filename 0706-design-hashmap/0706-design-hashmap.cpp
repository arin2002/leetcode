class MyHashMap {
public:
    
    // hash function key%size -> collisons (chaining must be done)
    // load factor hota h uske through chain ka size decide karenge
    
    // vector of linked list
    vector<list<pair<int,int>>> hashmap;
    // If you use 10007(nearest prime of size of array) then your solution would more efficient because Using nearest prime of size of array the chances of collision would be minimum and there will be more chances of equally distribution of element of array.

    int size = 1007;

    MyHashMap() {
        hashmap.resize(size);
    }
    
    void put(int key, int value) {
        // hash function
        int bucket_no = key%size;
        // chain where we will add
        auto &chain = hashmap[bucket_no];
        
        for(auto &[a,b]: chain){
            if(a == key){
                b = value;
                return;
            }
        }
        
        chain.emplace_back(key,value);
    }
    
    int get(int key) {
        // hash function
        int bucket_no = key%size;
        // chain where we will add
        auto &chain = hashmap[bucket_no];
        
        for(auto &[a,b]: chain){
            if(a == key){
                return b;
            }
        }
        
        return -1;
    }
    
    void remove(int key) {
        // hash function
        int bucket_no = key%size;
        // chain where we will add
        auto &chain = hashmap[bucket_no];
        
        for(auto it = chain.begin(); it != chain.end(); it++){
            auto k = it->first;
            
            if(k == key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */