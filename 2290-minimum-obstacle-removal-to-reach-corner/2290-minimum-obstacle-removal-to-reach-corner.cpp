class Solution {
    vector<vector<int>> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> distance(r, vector<int>(c, INT_MAX));
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        distance[0][0] = 0;
        dq.push_front({0,0});
        while (!dq.empty()) 
        {
            pair curr = dq.front();
            dq.pop_front();
            if (!visited[curr.first][curr.second]) 
            {
                visited[curr.first][curr.second] = true;
                for (auto m : moves) 
                {
                    int x = curr.first + m[0];
                    int y = curr.second + m[1];
                    if (x >= 0 && y >= 0 && x < r && y < c) 
                    {
                        if (distance[x][y] > distance[curr.first][curr.second] + grid[x][y]) 
                        {
                            distance[x][y] = distance[curr.first][curr.second] + grid[x][y];
                            if(grid[x][y]==0)
                                dq.push_front({x,y});
                            else
                                dq.push_back({x,y});
                        }
                    }
                }
            }
        }
        return distance[r - 1][c - 1];
    }
};
