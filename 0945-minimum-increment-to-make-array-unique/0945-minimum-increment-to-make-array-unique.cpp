class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int ans = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                int prevval = nums[i];
                int currval= nums[i - 1] + 1;
                nums[i] = currval;
                mp[nums[i]]++;
                ans += (currval - prevval);

            } else {
                mp[nums[i]]++;
            }
            maxi = max(maxi, nums[i]);
        }
        return ans;
    }
};
