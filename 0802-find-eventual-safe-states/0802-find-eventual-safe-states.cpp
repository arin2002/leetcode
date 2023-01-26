class Solution {
public:
    
    vector<int> vis,path, ans;
    
    
    bool dfs(int node,vector<vector<int>>& graph){
        vis[node] = 1;
        path[node] = 1;
         
        for(auto it : graph[node]){
            if(vis[it] == 0){
                if(dfs(it,graph) == true)
                    return true;
            }
            else if(path[it])
                return true;
        }
        
        path[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vis.resize(n);
        path.resize(n);
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i,graph);
            }
        }
        
        for(int i = 0; i<n; i++){
            if(path[i] == 0)
                ans.push_back(i);
        }
        
        return ans;
    }
};