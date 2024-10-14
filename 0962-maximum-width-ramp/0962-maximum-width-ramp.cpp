class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Build the 'v' array which contains the maximum from index j to n-1.
        vector<int> v(n, 0);
        int maxi = INT_MIN;
        for(int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, nums[i]);
            v[i] = maxi;
        }
        
        // Step 2: Two-pointer approach to find the maximum ramp width
        int i = 0, j = 0;
        int diff = 0;
        while(i < n && j < n) {
            
            // Move 'j' while nums[i] <= v[j] to find the maximum width ramp
            while(j < n && nums[i] <= v[j]) {
                diff = max(j - i, diff);
                j++;
            }
            i++;  // Move 'i' to check for the next potential ramp
        }
        return diff;  // Return the maximum width ramp found
    }
};
