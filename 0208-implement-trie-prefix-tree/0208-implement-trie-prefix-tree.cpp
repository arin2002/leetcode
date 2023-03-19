class Node{
    Node* links[26];
    bool flag = false;
    
    public:
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void put(Node *root,char ch){
        links[ch-'a'] = root;
    }
    
    Node* next(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    // for word completeness
    bool isEnd() {
		return flag;
	}
};


class Trie {
public:
    
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(auto &it: word){
            if(!node->containsKey(it)){
                node->put(new Node(),it);
            }
            
            // move to next
            node = node->next(it);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(auto &it: word){
            if(!node->containsKey(it))
                return false;
            
            node = node->next(it);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        
        for(auto &it: prefix){
            if(!node->containsKey(it))
                return false;
            
            node = node->next(it);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */