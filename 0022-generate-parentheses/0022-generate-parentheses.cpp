class Solution {
public:
    
    vector<string> ans;
    
    void f(string curr,int n,int open, int close, vector<string> &ans){
        if(curr.length() == n*2)
            ans.push_back(curr);
        
        if(open<n)
            f(curr+"(",n,open+1,close,ans);
        
        
        if(close < open)
            f(curr+")",n,open,close+1,ans);
    }
    
    vector<string> generateParenthesis(int n) {
        f("(",n,1,0,ans);
        
        return ans;
    }
};