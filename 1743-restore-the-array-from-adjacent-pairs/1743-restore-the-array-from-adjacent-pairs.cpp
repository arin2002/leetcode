class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        int n = adjacentPairs.size();
        
        unordered_map<int,int> vis, indegree;
        unordered_map<int,vector<int>> adj;
        
        
        for(auto &it: adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[1]]++;
            indegree[it[0]]++;
        }
                 
        function<void(int)> dfs = [&](int node){
            cout<<node<<" ";
            vis[node] = 1;
            ans.push_back(node);
            
            for(auto &neighb: adj[node]){
                if(!vis[neighb]){
                    dfs(neighb);
                }
            }
        };
        
        
        for(auto &it: indegree){
            if(it.second == 1){
                dfs(it.first);
                break;
            }
        }
        
        return ans;
    }
};