class Solution {
public:
    
    bool bfs(int node, vector<int> &color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        
        color[node] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : graph[node]){
                // not colored
                if(color[it] == -1){
                    // give opposite color
                    color[it] = !color[node];
                    q.push(it);
                }
                // same color
                else if(color[it] == color[node])
                    return 0;
            }
        }
        
        return 1;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // color array -1 means not colored
        vector<int> color(n,-1);
        
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if(!bfs(i,color,graph)){
                    return 0;
                }
            }
        }
        
        return 1;
    }
};