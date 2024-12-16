class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Initialize the heap with all elements and their indices
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        
        while (k--) {
            // Get the smallest element and its index
            auto [minValue, minIndex] = pq.top();
            pq.pop();
            
            // Update the corresponding element in the array
            nums[minIndex] *= multiplier;
            
            // Push the updated value back into the heap
            pq.push({nums[minIndex], minIndex});
        }
        
        return nums;
    }
};