class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0; // If there are 4 or fewer elements, we can make them all the same
        
        sort(nums.begin(), nums.end()); // Sort the array in non-decreasing order
        
        // Check all possible scenarios
        int min_diff = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            int modified_diff = nums[n - 4 + i] - nums[i]; // Calculate the difference between the largest and smallest elements in the chosen subarray
            min_diff = min(min_diff, modified_diff); // Update the minimum difference found so far
        }
        
        return min_diff; // Return the minimum difference found
    }
};
