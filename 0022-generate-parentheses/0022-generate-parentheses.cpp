class Solution {
public:
    
    vector<string> ans;
    
    void solve(string curr,int op, int clo, int n){
        
        if(curr.length() == 2*n)
            ans.push_back(curr);
        
        if(op<n){
            // curr.push_back('(');
            solve(curr+"(",op+1,clo,n);
        }
        
        if(clo<op){
            // curr.push_back(')');
            solve(curr+")",op,clo+1,n);
        }
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        solve("(",1,0,n);
        return ans;
    }
};