class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int ans = 1, start = 0;
        for(int end = 1; end<n; end++){
            if(nums[end] - nums[start] > k){
                start = end;
                ans++;
            }
        }
        return ans==1 ? ans++: ans;
    }
};