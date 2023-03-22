class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n+1];
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        vector<int> vis(n+1);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        int ans = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it: adj[node]){
                ans = min(ans,it.second);
                if(!vis[it.first]){
                    vis[it.first] = 1;
                    q.push(it.first);
                } 
            }
        }
        
        return ans;
    }
};