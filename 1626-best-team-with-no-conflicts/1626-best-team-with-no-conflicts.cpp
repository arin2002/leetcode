class Solution {
public:
    
    vector<pair<int,int>> vp;
    int dp[1001][1001];
    
    int solve(int ind, int prevAge){
        if(ind == vp.size())
            return 0;
        
        if(dp[ind][prevAge] != -1)
            return dp[ind][prevAge];
        
        // take
        int l = 0, r = 0;
        if(vp[ind].second >= prevAge){
            l = vp[ind].first + solve(ind+1,vp[ind].second);
        }
        
        // not take
        r = solve(ind+1,prevAge);
        
        return dp[ind][prevAge] = max(l,r);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0; i<scores.size(); i++)
            vp.push_back({scores[i],ages[i]});
        
        sort(vp.begin(),vp.end());
        return solve(0,0);
    }
};