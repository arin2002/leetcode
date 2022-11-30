class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int i = 0, j = nums.size() - 1;
        unordered_set<float> ht;
        while(i <= j){
            float avg = (nums[i] + nums[j]) / 2.0;
            ht.insert(avg);
            i++ , j--;
        }
        return ht.size();
    }
};
