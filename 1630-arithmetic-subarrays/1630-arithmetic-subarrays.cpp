class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans(m);
        
        function<bool(int,int)> solve = [&](int a, int b){
            // we need to find ap in O(n) time
            int n = b-a+1, mini = INT_MAX, maxi = INT_MIN;
            unordered_set<int> st;
            
            for(int i = a; i<b+1; i++){
                st.insert(nums[i]);
                
                mini = min(mini,nums[i]);
                maxi = max(maxi,nums[i]);
            }
            
            // an = a+(n-1)*d;
            if((maxi-mini)%(n-1) != 0)
                return false;
            
            int d = (maxi-mini)/(n-1);
            
            for(int i = 2; i<=n; i++){
                int ele = mini+(i-1)*d;
                
                if(st.find(ele) == st.end())
                    return false;
            }
            
            return true;
        };
        
        
        for(int i = 0; i<m; i++){
            if(solve(l[i],r[i])){
                ans[i] = true;
            }
        }
        
        return ans;
    }
};