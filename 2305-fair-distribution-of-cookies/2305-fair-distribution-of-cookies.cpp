class Solution {
public:
    vector<int> ans;
    int k;
    
    int solve(int ind, vector<int>& nums){
        if(ind == nums.size()){
            return *max_element(ans.begin(),ans.end());
        }
        
        int t = INT_MAX;
        for(int i = 0; i<k; i++){
            ans[i] += nums[ind];
            t = min(t,solve(ind+1,nums));
            ans[i] -= nums[ind];
            
            if(ans[i] <= 0)
                return t;
        }
        
        return t;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        this->k = k;
        ans.resize(k);
        return solve(0,cookies);
    }
};