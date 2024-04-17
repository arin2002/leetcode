class MyHashMap {
public:
    
    vector<int> ump;
    
    MyHashMap() {
        ump.resize(1000001,-1);
    }
    
    void put(int key, int value) {
        ump[key] = value;
    }
    
    int get(int key) {
        return ump[key];
    }
    
    void remove(int key) {
        ump[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */