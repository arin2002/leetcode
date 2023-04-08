class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
        }
        
        // kahns algo
        
        //find indegree
        vector<int> indegree(n,0);
        
        for(int i = 0; i<n; i++){
            for(auto &it: adj[i])
                indegree[it]++;
        }
        
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
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
        
        return ans.size() == n;
    }
};