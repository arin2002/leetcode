class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> ump;
        int maxi = 0, ans = 0;
        
        for(auto &it: edges){
            ump[it[0]]++;
            ump[it[1]]++;
            
            if(maxi < ump[it[0]]){
                maxi = ump[it[0]];
                ans = it[0];
            }
            
            if(maxi < ump[it[1]]){
                maxi = ump[it[1]];
                ans = it[1];
            }
        }
        
        return ans;
    }
};