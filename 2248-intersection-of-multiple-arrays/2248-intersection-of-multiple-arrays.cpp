class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int row = nums.size();
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                mpp[nums[i][j]]++;
                if(mpp[nums[i][j]]==row){
                    ans.push_back(nums[i][j]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
