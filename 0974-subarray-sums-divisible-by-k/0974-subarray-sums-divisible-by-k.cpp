class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> mod_count;
    int count = 0, sum = 0;
    mod_count[0] = 1;
    for (int num : nums) {
        sum += num;
        int mod = (sum % k + k) % k;
        count += mod_count[mod];
        mod_count[mod]++;
    }
    return count;
}

};