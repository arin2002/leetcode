class Solution {
public:
    int dp[101][101][2];
    
    int solve(int ind, int m, int person, vector<int>& piles){
        if(ind >= piles.size())
            return 0;
        
        if(dp[ind][m][person] != -1)
            return dp[ind][m][person];
        
        int temp = 0, ans = 0;
        if(person == 1)
            ans = INT_MAX;
        
        for(int i = ind; i<piles.size(); i++){
            if(i-ind+1 > 2*m)
                break;
            
            temp += piles[i];
            if(person == 1)
                ans = min(ans,solve(i+1,max(m,i-ind+1),0,piles));
            
            else
                ans = max(ans,temp+solve(i+1,max(m,i-ind+1),1,piles));
        }
        
        return dp[ind][m][person] = ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,piles);
    }
};