class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        unordered_set<int> marked;
        vector<int> sortedIdx;
        sortedIdx.reserve(nums.size());
        
        for (size_t idx = 0; idx < nums.size(); idx++) {
            sortedIdx.push_back(idx);
        }
        
        sort(sortedIdx.begin(), sortedIdx.end(), [&nums](int a, int b){
           return nums[a] != nums[b] ? nums[a] < nums[b] : a < b;
        });
        
        for (int idx : sortedIdx) {
            if (!marked.count(idx)) {
                score += nums[idx];
                marked.insert(idx);
                marked.insert(idx-1);
                marked.insert(idx+1);
            }
        }
            
        return score;
    }
};
