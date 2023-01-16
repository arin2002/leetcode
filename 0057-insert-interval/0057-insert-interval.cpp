class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        
        int a = newInterval[0], b = newInterval[1], x = -1;
        vector<vector<int>> ans;
        
        if(n == 0){
            ans.push_back({a,b});
            return ans;
        }
        
        //insert this new interval in our intervals
        bool flag = true;
        for(int i = 0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(start > a){
                x = i;
                break;
            }
                
        }
        
        // didnt get any place so add at last
        if(x == -1){
            intervals.push_back(newInterval);
        }
        
        else{
            intervals.insert(intervals.begin()+x,{a,b});
        }
        
        for(int i = 0; i<=n; i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<" ";
        }
        
        for(int i = 0; i<n; i++){
            
            if(intervals[i][1] >= intervals[i+1][0]){
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1],intervals[i+1][1]);
                
            }
            else
                ans.push_back({intervals[i][0], intervals[i][1]});
        }
        
        if(ans.size() == 0)
            ans.push_back({intervals[n][0],intervals[n][1]});
        
        else if(ans[ans.size()-1][0] < intervals[n][0] && ans[ans.size()-1][1] < intervals[n][1]){
            ans.push_back({intervals[n][0],intervals[n][1]});
        }
        
        return ans;
    }
};
