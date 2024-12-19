class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int idx = 0, maxidx = -1;
        int n = arr.size(), res = 0;
        while(idx < n) {
            maxidx = max(maxidx, arr[idx]);
            if(maxidx == idx) {
                res++, maxidx = -1;
            }
            idx++;
        }
        return res;
    }
};
