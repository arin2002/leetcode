class Solution {
public:
    bool row_check(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++) {
            char arr[10] = {'0'};
            for(int j = 0; j < 9; j++) {
                if(board[i][j] - '0' && board[i][j] != '.') {
                    if(!arr[board[i][j] - '0']) arr[board[i][j] - '0']++;
                    else return false;
                }
            }
        }    
        return true;
    }
    
    bool col_check(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++) {
            char arr[10] = {'0'};
            for(int j = 0; j < 9; j++) {
                if(board[j][i] - '0' && board[j][i] != '.') {
                    if(!arr[board[j][i] - '0']) arr[board[j][i] - '0']++;
                    else return false;
                }
            }
        }    
        return true;
    }
    
    bool check_box(vector<vector<char>>& board) {
        vector<set<int>> blocks(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') continue;
                
                int curr = board[i][j] - '0';
                if (blocks[(i/3)*3+j/3].count(curr)) 
                    return false;
                blocks[(i/3)*3+j/3].insert(curr);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row = true;
        row = row_check(board);
        if(!row) return row;
        
        row = col_check(board);
        if(!row) return row;
        
        row = check_box(board);
        if(!row) return row;
        return row;
    }
};
