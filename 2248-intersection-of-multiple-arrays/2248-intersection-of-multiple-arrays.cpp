class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                mp[nums[i][j]]++;
            }
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second==n){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
