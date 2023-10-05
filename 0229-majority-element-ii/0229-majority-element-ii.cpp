class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans ; 
        map<int, int> freq; 
         int n = nums.size(); 
        for(int i =0; i < nums.size(); i++)
        {
            if(freq[nums[i]]>=n/3)
            {
                ans.push_back(nums[i]);
                freq[nums[i]]= -1 ; 
                continue; 
            }
            if(freq[nums[i]]== -1 )
            continue; 
           
           freq[nums[i]]++;
        }
        return ans ;
    }
};
