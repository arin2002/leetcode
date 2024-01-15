class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int,int> ump;
        unordered_set<int> st;
        
        for(auto &it: matches){
            ump[it[1]]++;
        }
        
        for(auto &it: matches){
            if(ump.find(it[0]) == ump.end() && st.find(it[0]) == st.end()){
                ans[0].push_back(it[0]);
                st.insert(it[0]);
            }
            
            if(ump[it[1]] == 1 && st.find(it[1]) == st.end()){
                ans[1].push_back(it[1]);
                st.insert(it[1]);
            }
        }
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        
        return ans;
    }
};