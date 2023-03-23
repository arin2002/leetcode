class Solution {
public:
    
    vector<int> vis;
    
    void dfs(int ind, vector<int>adj[]){
        vis[ind] = 1;
        
        for(auto &it: adj[ind]){
            if(!vis[it])
                dfs(it,adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        
        if(m < n-1)
            return -1;
        
        vis.resize(n+1);
        vector<int> adj[n+1];
        
        for(auto &it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int connected = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                connected++;
                dfs(i,adj);
            }
        }
        
        return connected-1;
    }
};