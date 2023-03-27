class Solution {
public:
    
    vector<string> ans;
    
    void solve(int ind, string s){
        if(ind >= s.size()){
            ans.push_back(s);
            return;
        }
        
        if(isalpha(s[ind])){
            s[ind] = toupper(s[ind]);
            solve(ind+1,s);
            s[ind] = tolower(s[ind]);
            solve(ind+1,s);
        }
        else
            solve(ind+1,s);
    }
    
    vector<string> letterCasePermutation(string s) {
        solve(0,s);
        return ans;
    }
};