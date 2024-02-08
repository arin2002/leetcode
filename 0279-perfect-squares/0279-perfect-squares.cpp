class Solution {
    int targetSum(vector<int> &perfectSquares, int target, vector<int> &dp){
        if(target == 0)
            return 0;
        
        if(target < 0)
            return INT_MAX;
        
        if(dp[target] != INT_MAX)
            return dp[target];
        int minPerfectSquares = INT_MAX;
        for(int i = 0; i < perfectSquares.size(); i++){
            int ans = targetSum(perfectSquares, target-perfectSquares[i],dp);
            if(ans != INT_MAX)
                minPerfectSquares = min(minPerfectSquares, ans+1);
        }
        return dp[target] = minPerfectSquares;
    }
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        
        //perfectSquares that can be added to get the sum = n;
        int i = 1;
        while(i*i <= n){
            cout<<i*i<<endl;
            perfectSquares.push_back(i*i);
            i++;
        }
        vector<int> dp(n+1, INT_MAX);
        //now the question has been reduced to target sum question
        int minPerfectSquare = targetSum(perfectSquares, n, dp);
        return minPerfectSquare;
    }
};