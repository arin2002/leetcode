class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if(nums.size() == 0)
            return ans;
        
        int prev = nums[0], flag = 0; string temp = to_string(nums[0]);
        
        for(int  i = 1; i<nums.size(); i++){
            if(prev+1 == nums[i]){
                flag = 1;
            }
            else{
                if(flag){
                    ans.push_back(temp+"->"+to_string(prev));
                    flag = 0;
                }
                else{
                    ans.push_back(temp);
                }
                
                temp = to_string(nums[i]);
            }
            prev = nums[i];
        }
        
        if(flag)
            ans.push_back(temp+"->"+to_string(prev));
        else
            ans.push_back(temp);
        
        return ans;
    }
};