class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        
        function<void(int,int)>solve = [&](int ind, int k){
            if(ind  == n){
                if(k == 0){
                    ans.push_back(temp);
                }
                
                return;
            }
            
            if(nums[ind] <= k){
                temp.push_back(nums[ind]);
                solve(ind,k-nums[ind]);
                temp.pop_back();
            }
            
            solve(ind+1,k);
            
        };
        
        solve(0,target);
        return ans;
    }
};