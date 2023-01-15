class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m,0)), vis(n,vector<int>(m,0)); 
        queue<pair<pair<int,int>,int>> que;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    que.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else
                    vis[i][j] = 0;
            }
        }
        
        int drs[] = {-1,0,1,0,-1};
        
        while(!que.empty()){
            int x = que.front().first.first;
            int y = que.front().first.second;
            int val = que.front().second;
            que.pop();
            
            ans[x][y] = val;            
            for(int i = 0; i<4; i++){
                int x1 = x+drs[i];
                int x2 = y+drs[i+1];
                
                if(x1>=0 && x1<n && x2>=0 && x2<m){
                    if(!vis[x1][x2] && mat[x1][x2] == 1){
                        vis[x1][x2] = 1;
                        que.push({{x1,x2},val+1});
                    }
                }
            }
        }
        
        
        return ans;
    }
};