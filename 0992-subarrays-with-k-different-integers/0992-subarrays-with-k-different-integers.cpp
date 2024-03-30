class Solution {
public:

    int util(vector<int>& nums, int k){
        int l = 0, count = 0, n = nums.size();
        unordered_map<int,int> mp;
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(mp.find(nums[l]));
                }
                l++;
            }
            count += (r-l+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return (util(nums,k) - util(nums,k-1));
    }
};
