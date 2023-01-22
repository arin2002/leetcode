class Solution {
public:
    
    vector<vector<string>> ans;
    vector<string> temp;
    
    bool check(int low, int high, string &s){
        while(low<high){
            if(s[low++] != s[high--])
                return 0;
        }
        return 1;
    }
    
    void solve(int ind, string &s){
        if(ind >= s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = ind; i<s.size(); i++){
            if(check(ind,i,s)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s);
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        solve(0,s);
        return ans;
    }
};