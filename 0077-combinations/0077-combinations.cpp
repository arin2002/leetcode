class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> st;
    int n,k;
    
    void solve(int ind){
        if(ind == n+2)
            return;
        
        if(temp.size() == k){
            if(st.find(temp) == st.end()){
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
                
        for(int i = ind; i<=n; i++){
            temp.push_back(i);
            solve(i+1);
            temp.pop_back();
            // solve(ind+1);
        }
        // solve(ind+1);
    }
    
    vector<vector<int>> combine(int n, int k) {
        this->n = n; this->k = k;
        // if(n == k){
        //     for(int i = 1; i<=n; i++){
        //         temp.push_back(i);
        //     }
        //     ans.push_back(temp);
        //     retur
        // }
        
        solve(1);
        return ans;
    }
};