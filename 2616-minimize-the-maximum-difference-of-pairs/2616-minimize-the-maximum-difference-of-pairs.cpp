class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), ans = INT_MAX;
        int l = 0,  r = nums[n-1]-nums[0];
        
        function<bool(int)> solve = [&](int mid){
            int c = 0;
            for(int i = 1; i<n; i++){
                if(nums[i]-nums[i-1] <= mid){
                    c++;
                    i++;
                }
            }
            
            return c >= p;
        };
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            if(solve(mid)){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        
        return ans;
    }
};