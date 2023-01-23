class Solution {
public:
    unordered_set<int,int> ump;
    vector<int> temp;
    vector<vector<int>> ans;
    vector<int> vis;
    
    void solve(int ind, vector<int>& nums){
        
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(vis[nums[i]+10])
                continue;
            
            vis[nums[i]+10] = 1;
            temp.push_back(nums[i]);
            solve(i+1,nums);
            temp.pop_back();
            vis[nums[i]+10] = 0;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(40);
        
        solve(0,nums);
        return ans;
    }
};