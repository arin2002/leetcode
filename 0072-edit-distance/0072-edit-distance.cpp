class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int j, string &s, string &t){
        if(i<0 && j<0)
            return 0;
        
        // insert maar sakhte h isme ham i string mai
        if(i < 0 && j>=0){
            return j+1;
        }
        
        // isme delete kar do extra
        if(i>=0 && j<0){
            return i+1;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int l = 1000, r = 1000, z = 1000, p = 1000;
        // cout<<i<<" "<<j<<endl;
        if(s[i] == t[j]){
            l = solve(i-1,j-1,s,t);
        }
        else{
            // delete
            r = 1 + solve(i-1,j,s,t);
            // replace
            z = 1 + solve(i-1,j-1,s,t);
            // insert
            p = 1 + solve(i,j-1,s,t);
        }
        
        return dp[i][j] = min(l,min(r,min(z,p)));
    }
    
    
    int minDistance(string s, string t) {
        // vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        dp.resize(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(s.size(),t.size(),s,t);
    }
};