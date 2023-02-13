class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        
        int k = -1;
        for(auto it : intervals){
            if(ans.size() == 0 || ans[k][1] < it[0]){
                ans.push_back(it);
                k++;
            }
            else{
                ans[k][1] = max(it[1],ans[k][1]);
            }
        }
        
        return ans;
    }
};