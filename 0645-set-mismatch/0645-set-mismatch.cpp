class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,0);
        unordered_map<int,int> ump;
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int prev = 0;
        
        for(int  i = 0; i<n; i++){
            auto it = ump.find(nums[i]);
            
            if(it!= ump.end())
                ans[0] = it->first;
            
            prev+=nums[i];
            ump[nums[i]]++;
        }
        
        int sum = (n*(n+1))/2;
        // cout<<sum<<" "<<prev<<" ";
        ans[1] = sum-prev+ans[0];
        return ans;
    }
};