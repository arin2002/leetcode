class Solution {
public:
    
    void dfs(int node, int &ans, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        
        ans++;
        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(it,ans,vis,adj);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        
        for(int i = 0; i<n; i++){
            long long x1 = bombs[i][0], x2 = bombs[i][1];
            long long r = bombs[i][2];
            
            for(int j = 0; j<n; j++){
                
                if(j==i)
                    continue;
                
                long long x3 = bombs[j][0], x4 = bombs[j][1];
                
                // try to minimize sqrt divwion opeartion 
                long long d = (x3-x1)*(x3-x1)+(x4-x2)*(x4-x2);
                
                // cout<<d<<" "<<r<<endl;
                if(r*r >= d){
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            vector<int> vis(n);
            int t = 0;
            dfs(i,t,vis,adj);
            ans = max(ans,t);
        }
        
        return ans;
    }
};