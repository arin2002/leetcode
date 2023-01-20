class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> v;
    set<vector<int>> s;
    
    void solve(int ind, vector<int> &nums,int prev){
        if(ind == nums.size()){
            if(v.size() >= 2){
                s.insert(v);
            }
            return;
        } 
        
        if(nums[ind] >= prev){
            v.push_back(nums[ind]);
            solve(ind+1,nums,nums[ind]);
            v.pop_back();
        }
        
        solve(ind+1,nums,prev);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        solve(0,nums,-500);
        
        for(auto it :s)
            ans.push_back(it);
        
        return ans;
    }
};