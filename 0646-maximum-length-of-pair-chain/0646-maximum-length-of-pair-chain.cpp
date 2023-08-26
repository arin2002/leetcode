class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(n,vector<int>(n+2,-1));
        
        function<int(int,int)>solve = [&](int ind, int prev){
            if(ind == n)
                return 0;
            
            if(dp[ind][prev+1] != -1)
                return dp[ind][prev+1];
            
            int l = solve(ind+1,prev);
            if(prev == -1 || pairs[prev][1] < pairs[ind][0]){
                 l = max(l,1+solve(ind+1,ind));
            }
            
            return dp[ind][prev+1] = l;
        };
//         vector<int> temp;
//         temp.push_back(pairs[0][1]);
        
//         for(int i = 1; i<n; i++){
//             if(temp.back() < pairs[i][0])
//                 temp.push_back(pairs[i][0]);
            
//             else{
//                 int ind = lower_bound(temp.begin(),temp.end(),pairs[i][0])-temp.begin();
//                 temp[ind] = pairs[i][0];
//             }
//         }
        
        // return temp.size();
        return solve(0,-1);
    }
};