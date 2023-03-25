class Solution {
public:
    vector<int> vis;
    
    void dfs(int node, vector<int> adj[],long long &count){
        vis[node] = 1;
        count++;
        
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it,adj,count);
        }
    }
    
    long long countPairs(long long n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vis.resize(n);
        
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        long long ans = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                long long count = 0;
                dfs(i,adj,count);
                ans += (count*(n-count));
            }
        }
        
        return ans/2;
    }
};