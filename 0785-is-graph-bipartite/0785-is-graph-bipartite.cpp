class Solution {
public:
    vector<int> col;
    
    bool dfs(int node,int color, vector<vector<int>>& adj){
        
        for(auto &it: adj[node]){
            if(col[it] == -1){
                col[it] = !color;
                if(dfs(it,col[it],adj)){
                    return true;
                }
            }
            else if(col[node] == col[it]){
                return true;
            }
        }
        
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        col.resize(n,-1);
        
        for(int i = 0; i<n; i++){
            if(col[i] == -1){
                col[i] = 0;
                if(dfs(i,0,graph))
                    return false;
            }
        }
        
        return true;
    }
};