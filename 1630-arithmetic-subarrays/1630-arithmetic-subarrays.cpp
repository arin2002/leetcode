class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans(m);
        
        function<bool(int,int)> solve = [&](int a, int b){
            // we need to find ap in O(n) time
            int size = b - a + 1;
            long long mini = LLONG_MAX, maxi = LLONG_MIN;
            unordered_set<long long> st;
            
            for(int i = a; i <= b; i++){
                st.insert(nums[i]);
                
                mini = min(mini, 1LL * nums[i]);
                maxi = max(maxi, 1LL * nums[i]);
            }
            
            // an = a + (n-1) * d;
            
            if((maxi-mini)%(size-1) != 0)
                return false;
            
            
            long long d = (maxi - mini) / (size - 1);
            
            for(int i = 1; i <= size; i++){
                long long ele = mini + 1LL * (i - 1) * d;
                
                if(st.find(ele) == st.end())
                    return false;
            }
            
            return true;
        };
        
        
        for(int i = 0; i < m; i++){
            if(solve(l[i], r[i])){
                ans[i] = true;
            }
        }
        
        return ans;
    }
};
