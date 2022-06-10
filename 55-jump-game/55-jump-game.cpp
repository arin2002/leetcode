class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return 1;
        int maxi = 0;
        for(int i = 0; i<n && maxi>=i; i++)
        {
            if(nums[i] == 0) continue;
            maxi = max(nums[i]+i,maxi);
            cout<<maxi;
        }
        
        if(maxi >=n-1)
            return true;
        else 
            return false;
    }
};