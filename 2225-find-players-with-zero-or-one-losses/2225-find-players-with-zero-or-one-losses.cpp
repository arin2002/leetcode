class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2,vector<int>());    
        
        vector<int> losser(100001,-1);
        
        for(auto &it : matches){
            int win = it[0], loss = it[1];
            
            if(losser[win] == -1)
                losser[win] = 0;
            
            if(losser[loss] == -1)
                losser[loss] = 1;
            
            else
                losser[loss]++;
        }
        
        for(int i = 1; i<100001; i++){
            if(losser[i] == 0)
                ans[0].push_back(i);
            
            else if(losser[i] == 1)
                ans[1].push_back(i);
        }
        return ans;
    }
};