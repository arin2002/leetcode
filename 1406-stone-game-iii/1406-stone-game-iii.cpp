class Solution {
public:
    vector<int> dp;
    
    int solve(int ind, vector<int> &nums){
        if(ind >= nums.size())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int ans = INT_MIN, temp = 0;
        for(int i = 0; i<3; i++){
            if(i+ind < nums.size()){
                temp += nums[i+ind];
                ans = max(ans,temp-solve(i+ind+1,nums));
            }
        }
        
        return dp[ind] = ans;
    }
    
    string stoneGameIII(vector<int>& stoneValue){
        dp.resize(stoneValue.size(),-1);
        int ans =  solve(0,stoneValue);
        
        if(ans > 0){
            return "Alice";
        }
        else if(ans<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};