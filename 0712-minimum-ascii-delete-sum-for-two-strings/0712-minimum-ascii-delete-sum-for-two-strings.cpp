class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    
    int solve(int i, int j, string &s, string &t){
        if(i == n && j == m){
            return 0;
        }
        
        if(i == n){
            int sum = 0;
            for(int k = j; k<m; k++){
                sum += t[k];
            }
            
            return sum;
        }
        
        if(j == m){
            int sum = 0;
            for(int k = i; k<n; k++){
                sum += s[k];
            }
            
            return sum;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int z = INT_MAX;
        if(s[i] == t[j]){
            z = solve(i+1,j+1,s,t);
        }
            
        int l = (int)s[i]+solve(i+1,j,s,t);
        int r = (int)t[j]+solve(i,j+1,s,t);
            
        // cout<<l<<" "<<r<<endl;
        return dp[i][j] = min(l,min(r,z));
    }
    
    int minimumDeleteSum(string s, string t) {
        n = s.size(); m = t.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,s,t);
    }
};