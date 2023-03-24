class Solution {
public:
    int ans=0;
    void dfs(vector<pair<int,int>>adj[],int src,vector<int>&vis)
    {
        vis[src]=1;
        for(auto it:adj[src])
        {
            if(!vis[it.first])
            {
                if(it.second==1) ans++;
                dfs(adj,it.first,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>adj[n];
        for(auto it:connections)
        {
            // if we find 1 in this than that edge need to be reversed
            // as we were able to traverse forward with it
            adj[it[0]].push_back({it[1],1});
            // these links are for traversing ahead
            // virtual links so no impact
            adj[it[1]].push_back({it[0],0});
        }
        vector<int>vis(n,0);
        dfs(adj,0,vis);
        return ans;
    }
};
