class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // formula for box is (row/3)*3 + col/3
        
        unordered_set<string> st;
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                // har ke liye add karna ha
                // row, col, box
                
                if(board[i][j] == '.')
                    continue;
                
                // encoded in this form
                // check ho jayega aaise
                int box_number = (i/3)*3 + j/3;
                string row = "row" + to_string(i) + board[i][j];
                string col = "col" + to_string(j) + board[i][j];
                string box = "box" + to_string(box_number) + board[i][j];
                
                if(st.find(row) != st.end() || st.find(col) != st.end()){
                    return false;
                }
                
                if(st.find(box) != st.end())
                    return false;
                
                // add in set
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        
        return true;
    }
};
