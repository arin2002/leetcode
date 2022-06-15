// class Solution
// {
//     public:

//         int helper(int i, int prev, vector<int> nums, int n, vector<vector<int>> &dp)
//         {
//             if (i == n)
//                 return 0;
            
//             if(dp[i][prev+1] != -1)
//                 return dp[i][prev+1];
//             int l = helper(i + 1, prev, nums, n,dp);

//             if (prev == -1 || nums[i] > nums[prev])
//                 l = max(l, 1 + helper(i + 1, i, nums, n,dp));

//             return dp[i][prev+1]= l;
//         }

//     int lengthOfLIS(vector<int> &nums)
//     {
//         int n = nums.size();
        
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         return helper(0, -1, nums, n,dp);
//     }
// };

class Solution {
public:
    int f(int ind, int prev_index, vector<vector<int>> &dp, vector<int> &arr, int &n)
    {
        if (ind == n)
            return 0;
        if (dp[ind][prev_index+1] != -1)
            return dp[ind][prev_index+1];

        int len = f(ind + 1, prev_index, dp, arr, n); // not take
        if (prev_index == n-1 || arr[ind] > arr[prev_index])
            len = max(len, 1 + f(ind + 1, ind, dp, arr, n)); // take condition
        return dp[ind][prev_index+1] = len;
    }
    
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n+1 , -1));
        return f(0, n-1, dp, arr, n);
    }
};
