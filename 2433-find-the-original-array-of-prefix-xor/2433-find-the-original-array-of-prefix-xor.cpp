class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n,0);
        ans[0] = v[0];
        
        for(int i = 1; i<n; i++){
            ans[i] = v[i]^v[i-1];
        }
        
        return ans;
    }
};