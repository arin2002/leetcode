class Solution {
public:
    
    vector<int> vis;
    
    void dfs(int node, vector<vector<int>>& nums){
        vis[node] = 1;
        
        for(int i = 0; i<nums.size(); i++){
            if(!vis[i]){
                if(nums[node][i] == 1){
                    dfs(i,nums);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size(), ans = 0;
        vis.resize(n+1);
        for(int i = 0; i<nums.size(); i++){
            if(vis[i] == 0){
                ans++;
                dfs(i,nums);
            }
        }
        
        return ans;
    }
};