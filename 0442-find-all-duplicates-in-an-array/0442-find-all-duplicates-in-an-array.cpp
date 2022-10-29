class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;
        int n= nums.size();
        vector<int>v;
        
        for(int i=0;i<n;i++){
            if(m[nums[i]]++>0)
                v.push_back(nums[i]);
        }
        return v;
    }
};