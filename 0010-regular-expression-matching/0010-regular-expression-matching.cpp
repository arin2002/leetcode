class Solution {
public:
    bool f(int i,int j,string &s,string &p, vector<vector<int>> &dp)
    { 
        if(i<0 && j<0) return true;   //Both Strings Exhausted
        if(j<0 && i>=0) return false;  //p exhausted but s is remaining
        if(i<0 && j>=0)  //if s is exhausted by p remains , it will only be true if all charcter in p have *;
        {
            while(j>=0)
            {
                if(p[j]=='*') j-=2;
                else return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[j]==s[i] || p[j]=='.') return dp[i][j] = f(i-1,j-1,s,p,dp);
        
        if(p[j]=='*')
        {
            if(p[j-1]!=s[i] && p[j-1]!='.')
                return dp[i][j] = f(i,j-2,s,p,dp);  //Consider * to be empty
            else
            {
                return dp[i][j] = f(i,j-2,s,p,dp) || f(i-1,j,s,p,dp); 
                //These three case are as follows
                //consider * empty
                //consider * length>=1
            }
        }
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};
