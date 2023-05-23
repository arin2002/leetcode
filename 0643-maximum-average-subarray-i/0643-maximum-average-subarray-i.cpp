class Solution {
public:
    double findMaxAverage(vector<int>& nums, double k) {
        double ans = INT_MIN;
        int i = 0,j = 0, n = nums.size(), temp = 0;
        for( i = 0; i<k; i++){
            temp += nums[i];
            // ans = max((int)ans,temp);
        }
        
        ans = max((int)ans,temp);
        for(;i<n; i++){
            temp = temp+nums[i]-nums[j++];
            ans = max((int)ans,temp);
        }
        
        return ans/k;
    }
};