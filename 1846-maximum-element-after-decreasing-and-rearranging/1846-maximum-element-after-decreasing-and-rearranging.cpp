class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int maxV = 1;
        for(auto e : arr)
            if(e>maxV)
                maxV++;
        return maxV;
    }
};
