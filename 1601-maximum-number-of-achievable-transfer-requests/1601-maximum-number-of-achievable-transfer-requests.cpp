class Solution {
public:
    int ans = 0;
    vector<int> indegree;
    void solve(int i, int count, vector<vector<int>>& requests){
        if(i == requests.size()){
            for(auto &it: indegree){
                if(it){
                    return;
                }
            }
            
            ans = max(ans,count);
            return;
        }
        
        int u = requests[i][0], v = requests[i][1];
        indegree[u]--;
        indegree[v]++;
        
        solve(i+1,count+1,requests);
        
        // backtrack
        indegree[u]++;
        indegree[v]--;
        solve(i+1,count,requests);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        indegree.resize(n);
        solve(0,0,requests);
        
        return ans;
    }
};
