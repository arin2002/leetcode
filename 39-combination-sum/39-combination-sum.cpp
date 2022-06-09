class Solution {
public:
    vector<vector<int>>ans;
    
    void sum(int i, vector<int> nums, int target, vector<int> & temp,int n)
    {
        if(i>=n)
        {
            if(target == 0)
                ans.push_back(temp);
            
            return;
        }
        
        if(nums[i] <= target)
        {
            temp.push_back(nums[i]);
            sum(i,nums,target-nums[i],temp,n);
            temp.pop_back();
        }
        sum(i+1,nums,target,temp,n);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int n = candidates.size();
        int k = 0;
        sum(0,candidates,target,temp,n);
        return ans;
    }
};