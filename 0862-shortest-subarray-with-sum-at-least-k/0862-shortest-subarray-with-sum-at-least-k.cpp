class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> prefixSum(n + 1, 0);

        // Step 1: Calculate the prefix sums
        // The prefixSum[i+1] stores the sum of elements from nums[0] to nums[i].
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Step 2: Initialize a deque to maintain indices of prefix sums
        // The deque helps in efficiently checking for valid subarrays.
        std::deque<int> dq;
        int minLength = INT_MAX; // Initialize the minimum length to a very large value

        // Step 3: Iterate through the prefixSum array
        for (int i = 0; i <= n; i++) {
            // Step 3.1: Check if the current prefix sum forms a valid subarray with a sum >= k
            // If the difference between the current prefix sum and the smallest prefix sum
            // in the deque is >= k, we have found a valid subarray.
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                // Update the minimum length with the length of this valid subarray
                minLength = std::min(minLength, i - dq.front());
                dq.pop_front(); // Remove the front index as it has been processed
            }

            // Step 3.2: Maintain the deque in a monotonic increasing order
            // If the current prefix sum is smaller than the last prefix sum in the deque,
            // it means the subarray starting at the current index is more favorable.
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back(); // Remove the last index from the deque
            }

            // Step 3.3: Add the current index to the deque
            // This index will be used to calculate future subarray sums.
            dq.push_back(i);
        }

        // Step 4: Return the result
        // If no valid subarray is found, return -1. Otherwise, return the minimum length.
        return minLength == INT_MAX ? -1 : minLength;
    }
};
