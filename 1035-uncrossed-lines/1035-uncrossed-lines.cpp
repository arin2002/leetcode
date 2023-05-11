class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if(i>= n || j>= m)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int l = 0, r = 0;
        if(nums1[i] == nums2[j]){
            l = max(l,1+solve(i+1,j+1,nums1,nums2));
        }
        
        r = max(r,max(solve(i+1,j,nums1,nums2),solve(i,j+1,nums1,nums2)));
        return dp[i][j] = max(l,r);
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        dp.resize(n+2,vector<int>(m+2,-1));
        return solve(0,0,nums1,nums2);
    }
};