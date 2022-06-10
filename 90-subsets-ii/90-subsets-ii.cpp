class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void sub(vector<int> &nums, int it,int n)
    {
        ans.push_back(temp);
            
        for(int i = it; i<n ; i++){
            if(i>it && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            sub(nums, i+1,n);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        sub(nums, 0,nums.size());
        return ans;
    }
};
