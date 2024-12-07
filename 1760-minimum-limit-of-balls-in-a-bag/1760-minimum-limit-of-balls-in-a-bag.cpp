class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        int low = 1;
int high = *max_element(nums.begin(), nums.end());
while (low < high) {
    int mid = (low + high) / 2;
    int ops = 0;
    
    // Calculate total ops for current mid
    for (int n : nums) {
        ops += (n - 1) / mid;
        if (ops > maxOperations) {
            break;  // Early exit if operations exceed maxOperations
        }
    }

    // Adjust search range based on the ops
    if (ops <= maxOperations) {
        high = mid;  // Try for larger mid
    } else {
        low = mid + 1;  // Try for smaller mid
    }
}

return high;

    }
};
