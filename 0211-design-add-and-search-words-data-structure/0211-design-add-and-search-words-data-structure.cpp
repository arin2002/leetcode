class Node{
    
    public:
    
    Node* links[26];
    bool flag = false;
    
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void insert(char ch, Node *node){
        links[ch-'a'] = node;
    }
    
    Node* next(char ch){
        return links[ch-'a'];
    }
    
    bool isEnd(){
        return flag;
    }
    
    void setEnd(){
        flag = true;
    }
};

class WordDictionary {
public:
    Node *root;
    
    bool solve(Node *node, int ind, string &s){
        if(ind == s.size())
            return node->isEnd();
        
        if(s[ind] == '.'){
            for(auto &p : node->links){
                if(p != NULL){
                    if(solve(p,ind+1,s))
                        return true;
                }
            }
            
            return false;
        }
        else{
            if(!node->contains(s[ind]))
                return false;
            
            return solve(node->next(s[ind]),ind+1,s);
        }
    }
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        
        for(auto &it : word){
            if(!node->contains(it)){
                node->insert(it,new Node());
            }
            
            node = node->next(it);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        return solve(root,0,word);
    }
};