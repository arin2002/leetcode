class Solution {
public:
    vector<int> nums;
    int k;
    
    int solve(int i, vector<int>& cookies){
        if(i == cookies.size()){
            int maxi = INT_MIN;
            for(auto &it: nums){
                maxi = max(maxi,it);
            }
            
            return maxi;
        }
        
        int ans = INT_MAX;
        for(int j = 0; j<k; j++){
            nums[j] += cookies[i];
            ans = min(ans,solve(i+1,cookies));
            nums[j] -= cookies[i];
        }
        
        return ans;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        nums.resize(k);
        this->k = k;
        return solve(0,cookies);
    }
};