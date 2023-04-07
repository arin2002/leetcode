class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        int a = entrance[0], b = entrance[1];
        
        int drs[5] = {-1,0,1,0,-1};
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{a,b},0});
        
        int ans = -1; // Initialize answer to -1
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();
            maze[i][j] = '+'; // Mark current cell as visited
            
            // Check if current cell is an exit and not the entrance
            if(i == a && j == b) {
                // Skip if current cell is entrance
            } else if((i == n-1 || j == m-1 || i == 0 || j == 0)) {
                // Break if current cell is an exit and not visited
                ans = d;
                break;
            }
            
            for(int k = 0; k<4; k++){
                int x = i+drs[k], y = j+drs[k+1];
                if(x>=0 && x<n && y>=0 && y<m && maze[x][y] == '.'){
                    q.push({{x,y},d+1}); // Increment distance by 1
                    maze[x][y] = '+'; // Mark next cell as visited
                }
            }
        }
        
        return ans;
    }
};
