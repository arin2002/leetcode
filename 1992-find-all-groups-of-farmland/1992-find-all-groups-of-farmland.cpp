class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();
        int r = 0, c = 0;
        vector<int> drs{-1, 0, 1, 0, -1};

        // Lambda function for solving farmland
        function<void(int, int)> solve = [&](int i, int j) {
            if (i < 0 || j < 0 || i == n || j == m || land[i][j] == 0 || land[i][j] == 2)
                return;

            land[i][j] = 2;
            r = max(r, i);
            c = max(c, j);

            for (int k = 0; k < 4; k++) {
                int nx = i + drs[k];
                int ny = j + drs[k + 1];

                solve(nx, ny); // Call solve recursively
            }
        };

        // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    r = 0, c = 0;
                    solve(i, j); // Call solve function
                    ans.push_back({i, j, r, c});
                }
            }
        }

        return ans;
    }
};
