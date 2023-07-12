class Solution {
public:
    vector<int> ans;
    int n;
    vector<int> vis, inRecursion;
    
    bool solve(int node, vector<vector<int>>& graph){
        vis[node] = 1;
        inRecursion[node] = 1;
        
        for(auto &it: graph[node]){
            if(!vis[it]){
                if(solve(it,graph)){
                    return true;
                }
            }
            else if(inRecursion[it]){
                return true;
            }
        }
        
        inRecursion[node] = 0;
        return false;
    }
    
    void dfs(vector<vector<int>>& graph){        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                solve(i,graph);
            }
        }
        
        for(int i = 0; i<n; i++){
            if(!inRecursion[i]){
                ans.push_back(i);
            }
        }
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        vis.resize(n); inRecursion.resize(n);
        dfs(graph);
        return ans;
    }
};