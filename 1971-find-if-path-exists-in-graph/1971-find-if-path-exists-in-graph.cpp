class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n], vis(n);
        
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        function<bool(int)> dfs = [&](int node){
            if(node == destination){
                return true;
            }
            
            vis[node] = 1;
            for(auto &it: adj[node]){
                if(vis[it])
                    continue;
                
                vis[it] = 1;
                if(dfs(it)){    
                    return true;
                }
            }
            
            return false;
        };
        
        return dfs(source);
    }
};