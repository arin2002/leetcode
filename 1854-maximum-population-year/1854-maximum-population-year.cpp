class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        for(auto &it: logs){
            mp[it[0]]++;
            mp[it[1]]--;
        }
        
        int len = 0, count = 0, ans = 0; 
        for(auto [a,b] : mp){
            len += b;
            if(len > count){
                count = len;
                ans = a;
            }
        }
        
        return ans;
    }
};