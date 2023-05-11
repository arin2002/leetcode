class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    int solve(int i, int prev, vector<int>& nums1, vector<int>& nums2){
        if(i>=nums1.size() )
            return 0;
        
        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];
        
        int l = 0, r = 0;
        for(int j = prev+1; j<nums2.size(); j++){
            if(nums1[i] == nums2[j]){
                l = max(l,1+solve(i+1,j,nums1,nums2));
            }
        }
        
        r = solve(i+1,prev,nums1,nums2);
        return dp[i][prev+1] = max(l,r);
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        dp.resize(n+2,vector<int>(m+2,-1));
        return solve(0,-1,nums1,nums2);
    }
};