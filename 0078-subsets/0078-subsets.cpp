class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        
        function<void(int)> solve = [&](int ind){
            if(ind == nums.size()){
                ans.push_back(temp);
                return;
            }
            
            temp.push_back(nums[ind]);
            solve(ind+1);
            temp.pop_back();
            solve(ind+1);
        };
        
        solve(0);
        return ans;
    }
};