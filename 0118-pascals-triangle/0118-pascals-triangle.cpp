class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        for(int size = 1; size<=n; size++){
            vector<int> v(size,1);
            
            for(int i = 1; i<size-1; i++){
                v[i] = ans[size-2][i-1]+ans[size-2][i];
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};