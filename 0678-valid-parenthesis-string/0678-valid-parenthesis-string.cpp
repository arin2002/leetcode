class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(101,-1));
        
        function<bool(int,int)> solve = [&](int i, int open){
            if(open<0)
                return 0;
            
            if(i == n){
                if(open == 0)
                    return 1;
                
                return 0;
            }
            
            if(dp[i][open] != -1)
                return dp[i][open];
            
            int l = 0,r = 0,z = 0;
            if(s[i] == '('){
                l = solve(i+1,open+1);
            }
            
            if(s[i] == ')'){
                r = solve(i+1,open-1);
            }
            
            if(s[i] == '*'){
                z = solve(i+1,open+1) | solve(i+1,open-1) | solve(i+1,open);
            }
            
            return dp[i][open] = l|r|z;
            
        };
        
        return solve(0,0);
    }
};