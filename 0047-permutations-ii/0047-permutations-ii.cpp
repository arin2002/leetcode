class Solution {
public:
    
    vector<int> permu, vis;
    set<vector<int>> st;
    
    
    void solve(int ind, vector<int> &nums){
        if(permu.size() == nums.size()){
            st.insert(permu);
            return;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(vis[i+10])
                continue;
            vis[i+10] = 1;
            permu.push_back(nums[i]);
            solve(ind+1,nums);
            vis[i+10] = 0;
            permu.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis.resize(30);
        
        solve(0,nums);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};