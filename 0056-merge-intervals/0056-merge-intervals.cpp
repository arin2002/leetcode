class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        if(intervals.size() <= 1)
            return intervals;
        
        // temp vector comapre vagera le liye
        
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        
        for(auto it : intervals){
            if(it[0] <= temp[1]){
                temp[1] = max(temp[1],it[1]);
            }
            else{
                ans.push_back(temp);
                temp = it;
            }
            
            // cout<<temp[0]<<" "<<temp[1]<<endl;
        }
        
        ans.push_back(temp);
        return ans;
    }
};