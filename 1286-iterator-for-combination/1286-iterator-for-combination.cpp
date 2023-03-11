class CombinationIterator {
public:
    
    string s; int n, i = 0;
    vector<string> ans;
    
    void solve(int ind, string temp, int k, string &s){
        if(ind >= s.size()){
            if(temp.size() == k){
                cout<<temp<<endl;
                ans.push_back(temp);
            }
            return;
        }
        
        solve(ind+1,temp+s[ind],k,s);
        solve(ind+1,temp,k,s);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        s = characters; n = combinationLength;
        solve(0,"",n,s);
    }
    
    string next() {
        return ans[i++];
    }
    
    bool hasNext() {
        if(i == ans.size())
            return false;
        
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */