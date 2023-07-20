class Solution {
public:
    vector<int> vis;
    int n;
    
    void dfs(int node, vector<vector<int>>& graph){
        vis[node] = 1;
        
        for(auto &it: graph[node]){
            if(!vis[it]){
                dfs(it,graph);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vis.resize(n);
        dfs(0,rooms);
        
        for(auto &it: vis){
            if(!it)
                return 0;
        }
        
        return 1;
    }
};