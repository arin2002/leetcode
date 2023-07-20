class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> vis;
    int n;
    
    void solve(int ind, vector<vector<int>>& graph){
        if(ind == n-1){
            ans.push_back(temp);
            return;
        }
        
        vis[ind] = 1;
        for(auto it: graph[ind]){
            if(!vis[it]){
                temp.push_back(it);
                solve(it,graph);
                temp.pop_back();
            }
        }
        vis[ind] = 0;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis.resize(n);
        temp.push_back(0);
        solve(0,graph);
        return ans;
    }
};