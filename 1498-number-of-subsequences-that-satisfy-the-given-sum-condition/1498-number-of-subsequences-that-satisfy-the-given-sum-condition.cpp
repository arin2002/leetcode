class Solution {
public:
    int mod = 1e9+7;
    
    int bs(int i, int target, vector<int> &nums){
        int l = i, r = nums.size()-1;
        
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            
            if(nums[i]+nums[mid] <= target){
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        
        return ans;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), ans = 0;
        
        // precalculate power
        // most imp step
        int power[n];
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        
        //  2 pointer can be used more intiutive
        int i = 0, j = n-1;
        while(i<=j){
            if(nums[i]+nums[j] <= target){
                ans = ((ans%mod)+power[j-i]%mod)%mod;
                i++;
            }
            else
                j--;
        }
        
        return ans;
    }
};