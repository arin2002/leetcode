using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size();) {
            // Check if the current number is the same as the next number
            if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                // Skip the next number as well, as it is a duplicate
                i += 2;
            } else {
                // If the current number is not a duplicate, add it to the result
                result.push_back(nums[i]);
                i++;
            }
        }
        
        return result;
    }
};
