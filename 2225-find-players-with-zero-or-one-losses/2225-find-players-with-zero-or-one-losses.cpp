class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        
        map<int,int> mp1;
        map<int,int> mp2;
        
        for(int i = 0; i<matches.size(); i++){
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }
        
        vector<int> v1,v2;
        for(auto [i,j] : mp1){
            if(j >= 1 && mp2.find(i) == mp2.end())
                v1.push_back(i);
        }
        
        for(auto [i,j] : mp2){
            if(j == 1)
                v2.push_back(i);
        }
        
        ans.push_back(v1);
        ans.push_back(v2);
        
        
        return ans;
    }
};