class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        
        int n = nums.size();
        vector<long long> pre(n+1), suff(n+1);
        
        for(int i = 0; i<n; i++){
            pre[i+1] = pre[i] + nums[i];
        }
        
        for(int i = n-1; i>=0; i--){
            suff[i] = suff[i+1] + nums[i];
        }
        
        int temp = 0, avg = INT_MAX, ans = 0;
        for(int i = 0; i<nums.size(); i++){
            long long left = (pre[i+1])/(i+1);
            long long right = (suff[i+1]);
            
            if(i != n-1)
                right/= (n-i-1);
            
            int t = abs(left-right);
            if(t<avg){
                avg = t;
                ans = i;
            }
        }
        
        return ans;
    }
};