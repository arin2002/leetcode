class Solution {
public:
    
    // odd length wali nhi hogai bipartite
    bool dfs(int node, vector<int> &color, vector<vector<int>>& graph,int col){        
        for(auto it : graph[node]){
            if(color[it] == -1){
                color[it] = !col;
                // for subtree
                if(!dfs(it,color,graph,color[it]))
                    return 0;
            }
            else if(color[it] == color[node])
                return 0;
        }
        
        return 1;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // color array -1 means not colored
        vector<int> color(n,-1);
        
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i,color,graph,0))
                    return 0;
            }
        }
        
        return 1;
    }
};