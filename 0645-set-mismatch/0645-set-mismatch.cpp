class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,0);
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int prev = 0;
        for(int i = 0; i<n; i++){
            prev += nums[i];
        }
        
        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1]){
                ans[0] = nums[i];
                break;
            }
        }
        
        int sum = (n*(n+1))/2;
        // cout<<sum<<" "<<prev<<" ";
        ans[1] = sum-prev+ans[0];
        return ans;
    }
};