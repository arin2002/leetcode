class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> ump;
        for(auto i : nums)
            ump[i]++;
        
        for(int i = 0; i<n; i++)
        {
            long long int temp = nums[i]*2;
            auto it = ump.find(temp);
            
            if(it!=ump.end()){
                if(nums[i] == 1 || nums[i] == 0)
                {
                    if(it->second >=2)
                        return true;
                }
                else
                    return true;
            }
        }
        
        return false;
    }
};