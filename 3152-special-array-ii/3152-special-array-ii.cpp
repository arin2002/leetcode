class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;
        int curr = 0;
        int i = 1;
        mp[0] = curr;
        int n = nums.size();
        while(i<n)
        {
            int val = (nums[i]%2)^(nums[i-1]%2);
            if(val)
            {
                mp[i] = curr;
            }else
            {
                curr++;
                mp[i] = curr;
            }
            i++;
        }
        n = queries.size();
        vector<bool> ans;
        for(int i = 0;i<n;i++)
        {
            if(mp[queries[i][0]]==mp[queries[i][1]])
            {
                ans.push_back(true);
            }else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
