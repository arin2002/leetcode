class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int maxi = 0;
        for(auto &it: nums){
            it *= it;
            maxi = max(it,maxi);
        }
        
        // sort(nums.begin(),nums.end());
        vector<int> v(maxi+1);
        
        for(auto &it: nums){
            v[it]++;
        }
        
        int j = 0;
        for(int i = 0; i<=maxi; i++){
            while(v[i]-->0){
                nums[j++] = i;
            }
        }
        return nums;
    }
};