class Trie {
public:
    
    unordered_map<string,int> ump;
    
    Trie() {
        
    }
    
    void insert(string word) {
        ump[word] = 1;
    }
    
    bool search(string word) {
        auto it = ump.find(word);
        
        if(it == ump.end())
            return false;
        
        return true;
    }
    
    bool startsWith(string prefix) {
        for(auto [s,t] : ump){
            int i = 0, n = s.size(), m = prefix.size();
            
            while(i<n && i<m && s[i] == prefix[i])
                i++;
            
            if(i == m)
                return true;
        }
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */