class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int count = 0, sum = 0;
    unordered_map<int, int> sums;
    sums[0] = 1;
    for (int num : nums) {
        sum += num;
        count += sums[sum - k];
        sums[sum]++;
    }
    return count;
}

};