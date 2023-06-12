class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if(nums.size() == 0)
            return ans;
        
        int small = nums[0], large = nums[0];
        int n = nums.size();
        bool flag = 0;
        
        for(int i = 0;i<n-1; i++){
            if(nums[i]+1 == nums[i+1]){
                large = nums[i+1];
            }
            else{
                if(small != large)
                    ans.push_back(to_string(small)+"->"+to_string(large));
                else
                    ans.push_back(to_string(small));
                
                small = large = nums[i+1];
                if(i == n-2) flag = 1;
            }
        }
        
            if(small != large)
                    ans.push_back(to_string(small)+"->"+to_string(large));
                else
                    ans.push_back(to_string(small));        
        return ans;
    }
};