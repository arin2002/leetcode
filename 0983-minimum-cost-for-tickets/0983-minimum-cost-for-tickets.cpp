class Solution {
public:
    // vector<vector<int>> dp;
    vector<int> dp;
//     int solve(int ind, int valid, vector<int>& days, vector<int>& costs){
//         if(ind == days.size())
//             return 0;
        
//         if(dp[ind][valid] != - 1)
//             return dp[ind][valid];
        
//         // jabh tak valid ha kuch nhi karna
//         // ye base case sochna thoda hard ha    
//         if(days[ind]<=valid)
//             return dp[ind][valid] = solve(ind+1,valid,days,costs);
        
//         int l = 1000, r = 1000, z = 1000;
        
//         l = costs[0] + solve(ind+1,days[ind],days,costs);
//         r = costs[1] + solve(ind+1,days[ind]+6,days,costs);
//         z = costs[2] + solve(ind+1,days[ind]+29,days,costs);
        
        
//         return dp[ind][valid] = min(l,min(r,z));
//     }
    
    int nextDay(vector<int> &days, int i, int j){
        if(j == 0)
            return days[i]+1;
        
        if(j == 1)
            return days[i]+7;
        
        return days[i]+30;
    }
    
    int find(vector<int> &days, int i, int j){
        int next = nextDay(days, i, j);
        while (i < days.size() && days[i] < next) i++;
        return i;
    }
    
    int solve(int ind, vector<int>& days, vector<int>& costs){
        if(ind >= days.size())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
            
        int ans = INT_MAX;
        for(int i = 0; i<3; i++){
            int next = find(days,ind,i);
            ans = min(ans,costs[i]+solve(next,days,costs));
        }
        
        return dp[ind] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // dp.resize(days.size(),vector<int>(396,-1));
        dp.resize(days.size(),-1);
        return solve(0,days,costs);
    }
};