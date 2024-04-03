class Solution {
public:
    
    vector<int> drs{-1,0,1,0,-1};
    int n,m,l;
    
    bool solve(int i, int j, int k, vector<vector<int>> &vis, vector<vector<char>>& board, string &word){
        if(k == l){
            return true;
        }
        
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || board[i][j] != word[k])
            return false;
        
        vis[i][j] = 1;
        
        for(int x = 0; x<4; x++){
            int nx = i+drs[x], ny = j+drs[x+1];
            
            if(solve(nx,ny,k+1,vis, board, word)){
                return true;
            }
        }
        
        vis[i][j] = 0;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(); m = board[0].size(), l = word.size();
        vector<vector<int>> vis(n,vector<int>(m));
        
        // prune 1
        if(n*m < l){
            return false;
        }
        
        // prune 2
        unordered_map<char,int> ump;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ump[board[i][j]]++;
            }
        }
        
        for(auto &it: word){
            ump[it]--;
            
            if(ump[it]<0)
                return false;
        }
        
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(solve(i,j,0,vis,board,word))
                    return true;
            }
        }
        
        return false;
    }
};