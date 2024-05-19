class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> xored(nums.size());
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            xored[i]=(nums[i]^k)-nums[i];
            ans+=nums[i];
        }
        sort(xored.begin(),xored.end(),[](auto lhs,auto rhs){
            return lhs>rhs;
        });
        int i=0;
        while(i<xored.size()){
            if(i+1<xored.size() && xored[i]+xored[i+1]>0)
                ans+=xored[i]+xored[i+1];
            else
                break;
            i+=2;
        }
        return ans;
    }
};
