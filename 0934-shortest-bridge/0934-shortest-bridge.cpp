class Solution {
public:
    queue<pair<int, pair<int, int>>> q;
    // vector<vector<int>> vis;
    int n;
    vector<int> drs = {-1, 0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || grid[i][j] == 0) {
            return;
        }

        vis[i][j] = 1;
        q.push({0, {i, j}});

        for (int k = 0; k < 4; k++) {
            dfs(i + drs[k], j + drs[k + 1], grid, vis);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        // vis.resize(n, vector<int>(n, 0));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        // Find the first island using DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    // dfs(i, j, grid);
                    dfs(i, j, grid, vis);
                    break;
                }
            }
            if (!q.empty()) {
                break;
            }
        }
        
        cout<<q.size();
        while (!q.empty()) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int temp = q.front().first;
            q.pop();

            vis[x][y] = 1;

            for (int i = 0; i < 4; i++) {
                int newX = x + drs[i];
                int newY = y + drs[i + 1];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]) {
                    if (grid[newX][newY] == 1) {
                        return temp;
                    }
                    q.push({temp + 1, {newX, newY}});
                    vis[newX][newY] = 1;
                }
            }
        }

        return 0;
    }
};
