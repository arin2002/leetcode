class Solution {
public:
    
    bool f(vector<vector<char>>& board,string word,int i,int j,int n,int m,int k){
        if(k >= word.size())return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.' || word[k]!=board[i][j]) return false;
        // if(word.size() == 1 && word[k]==board[i][j]) return true;
        board[i][j] = '.';
        bool temp = false;
        int x[4] = {0,0,-1,1};
        int y[4] = {-1,1,0,0};
        for(int index=0;index<4;index++){
            temp = temp || f(board,word,i+x[index],j+y[index],n,m,k+1);
        }
        board[i][j] = word[k];
        return temp;
    }
    
    
    bool exist(vector<vector<char>>& b, string word) {
        int n = b.size(), m = b[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));       
        // sabh words ke liye check karenge ki sahi h ki nhi
        // aagar matching ho rhaa tabhi call karenge recursion ko
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(word[0] == b[i][j])
                    if(f(b,word,i,j,n,m,0))
                        return true;
            }
        }
        
        return false;
    }
};