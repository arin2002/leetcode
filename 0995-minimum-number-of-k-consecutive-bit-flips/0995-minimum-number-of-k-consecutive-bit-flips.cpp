class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> flipEnds;
        int flips = 0;

        for (int i = 0; i < n; ++i) {
            if (!flipEnds.empty() && flipEnds.front() <= i) {
                flipEnds.pop();
            }
            if ((nums[i] == 0 && flipEnds.size() % 2 == 0) || (nums[i] == 1 && flipEnds.size() % 2 != 0)) {
                if (i + k > n) {
                    return -1;
                }
                flipEnds.push(i + k);
                flips++;
            }
        }
        return flips;
    }
};
