class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ans = 1, n = nums.size();
        
        int currMax = nums[0], possMax = nums[0];
        for(int i = 1; i<n; i++){
            if(currMax > nums[i]){
                ans = i+1;
                currMax = possMax;
            }
            else{
                possMax = max(possMax,nums[i]);
            }
        }
        
        return ans;
    }
};