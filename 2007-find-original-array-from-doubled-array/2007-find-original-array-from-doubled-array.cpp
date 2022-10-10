class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        
        
        if(n%2 != 0)
            return ans;
        
        sort(v.begin(),v.end());
        unordered_map<int,int> ump;
        for(int i = 0; i<n; i++)
            ump[v[i]]++;
        
        for(int i = 0; i<n; i++){
            if(ans.size() == n/2)
                return ans;
            
            if(ump[v[i]] == 0)
                continue;
            
            if(v[i]*2 == v[i]){
                if(ump[v[i]*2] > 1){
                    ans.push_back(v[i]);
                    ump[v[i]]--;
                    ump[v[i]]--;
                }
            }
            
            else if(ump[v[i]*2] !=0){
                ans.push_back(v[i]);
                ump[v[i]*2]--;
                ump[v[i]]--;
            }
        }
        
        return vector<int>();
    }
};