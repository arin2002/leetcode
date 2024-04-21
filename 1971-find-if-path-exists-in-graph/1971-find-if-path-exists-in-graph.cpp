class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n], vis(n);

        // Populate adjacency list
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Depth-first search function
        return dfs(source, destination, adj, vis);
    }

    // Depth-first search function definition
    bool dfs(int node, int destination, vector<int> adj[], vector<int>& vis) {
        if (node == destination) {
            return true;
        }

        vis[node] = 1;
        for (auto &it : adj[node]) {
            if (vis[it]) {
                continue;
            }

            vis[it] = 1;
            if (dfs(it, destination, adj, vis)) {
                return true;
            }
        }

        return false;
    }
};
