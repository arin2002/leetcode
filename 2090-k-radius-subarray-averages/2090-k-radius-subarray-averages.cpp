class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        
        long long sum = 0;
        for(int i = 0; i<2*k && i<n; i++){
            sum += (long long)nums[i];
        }
        
        int K = k, j = 0;
        for(int i = 2*k; i<n; i++){
            sum += (long long)nums[i];
            // cout<<sum<<" ";
            ans[K++] = sum/(2*k+1);
            sum-=nums[j++];
        }
        
        return ans;
    }
};