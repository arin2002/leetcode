class RandomizedSet {
public:
    unordered_map<int,int> st;
    vector<int> v;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto it = st.find(val);
        
        if(it != st.end()){
            return false;
        }
        
        v.push_back(val);
        st[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        auto it = st.find(val);
        int n = v.size();
        
        if(it == st.end())
            return false;
        
        int ind = st[val];
        v[ind] = v.back();
        v[n-1] = val;
        st[v[ind]] = ind;
        v.pop_back();
        
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        return v[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */