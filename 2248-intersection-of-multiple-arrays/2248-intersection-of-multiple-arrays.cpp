class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        //sort(nums.begin(), nums.end());
        map<int,int> m;
        vector<int> v;
        for(int i = 0 ; i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                m[nums[i][j]]++;
                auto it = m.find(nums[i][j]);
                
                if(it != m.end() && it->second == n)
                    v.push_back(it->first);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};