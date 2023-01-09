class Solution {
public:
    
    int vis[300] = {0};
    
    
    void dfs(int i, vector<vector<int>> &nums, int n){
        vis[i] = 1;
        
        for(int j = 0; j<n; j++){
            if(!vis[j] && nums[i][j]==1)
                dfs(j,nums,n);
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size(),  ans = 0;
        
        // check for all nodes
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i,nums,n);
                ans++;
            }
        }
        
        return ans;
    }
};