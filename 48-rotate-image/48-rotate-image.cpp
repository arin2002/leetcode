class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n = nums.size();
        
        reverse(nums.begin(),nums.end());
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(nums[i][j],nums[j][i]);
            }
        }
        
        // for(int i = 0; i<n; i++){
        //     reverse(nums[i].begin(),nums[i].end());
        // }
    }
};