class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        vector<int> ans(n);
        int pos = 0, neg = 1;
        
        for(auto it: nums){
            if(it<0){
                ans[neg] = it; 
                neg += 2;
            }
            else{
                ans[pos] = it;
                pos += 2;
            }
        }
        
        return ans;
    }
};