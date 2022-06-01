class Solution {
public:
    vector<int> decode(vector<int>& nums, int first) {
        int n = nums.size();
        vector<int> v(n+1,0);
        v[0] = first;
        for(int i = 0;i<n;i++)
            v[i+1] = nums[i] ^ v[i];
        
        return v;
    }
};