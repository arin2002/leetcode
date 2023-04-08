class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> ans, adj[n], indegree(n);
        queue<int> q;
        
        // make adj list
        for(auto &it: edges){
            // main logic
            adj[it[1]].push_back(it[0]);
        }
        
        // do topo sort
        for(int i = 0; i<n; i++){
            for(auto &it: adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto &it: adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        if(ans.size() != n)
            return {};
        
        return ans;
    }
};