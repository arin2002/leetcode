class Solution {
    #define ll long long
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
     int n=nums.size();
     ll maxsum=0;
     unordered_map<int,int> mp;
     ll winsum=0;
     for(int i=0;i<n;i++)
     {
        mp[nums[i]]++;
        winsum+=nums[i];

        if(i>=k){
            winsum-= nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
        }
        if(i>=k-1 && mp.size()==k)
        {
            maxsum=max(maxsum,winsum);
        }
     }
     return maxsum;
    }
};
