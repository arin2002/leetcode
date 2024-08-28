class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<vector<int>>& t, int r, int c) {
        if (g[r][c] == 0) return true;
        if (t[r][c] == 0) return false;
        g[r][c] = 0;
        bool f = true;
        if (r < g.size() - 1) {
            f = f & dfs(g, t, r + 1, c);
        }
        if (r > 0) {
            f = f & dfs(g, t, r - 1, c);
        }
        if (c < g[0].size() - 1) {
            f = f & dfs(g, t, r, c + 1);
        }
        if (c > 0) {
            f = f & dfs(g, t, r, c - 1);
        }
        return f;
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int count = 0;
        for (int i = 0; i < g2.size(); ++i) {
            for (int j = 0; j < g2[0].size(); ++j) {
                if (g2[i][j] == 0) continue;
                count += dfs(g2, g1, i, j); 
            }
        }    
        return count;
    }
};
