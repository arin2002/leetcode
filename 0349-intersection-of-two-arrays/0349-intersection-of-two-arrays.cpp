class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq(1001), ans;
        
        for(auto &it: nums1){
            freq[it]++;
        }
        
        for(auto &it: nums2){
            if(freq[it]){
                freq[it] = 0;
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};