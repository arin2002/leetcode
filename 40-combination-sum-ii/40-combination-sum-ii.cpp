class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> v;
    
    void sum(int itr,vector<int> nums,int target,int n)
    {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i = itr; i<n; i++)
        {
            if(i>itr  && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) return;
            temp.push_back(nums[i]);
            sum(i+1,nums,target-nums[i],n);
            temp.pop_back();
        }
        //sum(i+1,nums,target,n);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        sum(0,candidates,target,n);
        return ans;
    }
};